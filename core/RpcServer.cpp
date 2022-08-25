/*
 * Copyright © 2022 Aurora open source project
 *
 * This is the source code of Aurora RPC linux based remote producer call system.
 * It is licensed under GNU GPL v.2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Author:  Abolfazl Abbasi
 *
 */

#include <unistd.h>
#include <vector>
#include "RpcServer.h"
#include "ByteBuffer.h"

#define READ_BUFFER_SIZE 1024 * 8

RpcServer::RpcServer() {
    std::cout << "RpcServer" << std::endl;

    pthread_create(&networkThread, nullptr, RpcServer::ThreadProc, this);

    if ((socketFd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket");
        exit(1);
    }

    if (setsockopt(socketFd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, (const void *) 1, sizeof(int)) == 0) {
        perror("set socket option");
        exit(2);
    }

    socketAddress.sin_family = AF_INET;
    socketAddress.sin_port = htons(1067);
    socketAddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(socketFd, (const sockaddr *) &socketAddress, sizeof(socketAddress)) < 0) {
        perror("bind");
        exit(2);
    }

    if (listen(socketFd, 1) < 0) {
        perror("listen");
        exit(4);
    }
}

void *RpcServer::ThreadProc(void *data) {
    auto server = (RpcServer *) (data);

    do {
        std::cout << "ThreadProc " << time(nullptr) << std::endl;
        server->socketListen();
    } while (true);
    return nullptr;
}


RpcServer::~RpcServer() {
    std::cout << "~RpcServer" << std::endl;
    close(socketFd);
}

void RpcServer::wait() {
    pthread_join(networkThread, nullptr);
}

void RpcServer::socketListen() {
    struct sockaddr clientAddres{};
    socklen_t clientSize;
    if ((clientSocket = accept(socketFd, (sockaddr *) &clientAddres, &clientSize)) < 0) {
        perror("accept");
        exit(3);
    }
    std::cout << "new connection established" << std::endl;

//    auto *buffer = new ByteBuffer(READ_BUFFER_SIZE);
    auto buffer = new uint8_t;
    size_t writeCount = 0;
    while (true) {
        size_t readCount = read(clientSocket, buffer, READ_BUFFER_SIZE);
        std::cout << "buffer sleep read count is: " << readCount << std::endl;

        if (readCount == 0) {
            exit(1);
        } else if (readCount > READ_BUFFER_SIZE) {

        }


        if (readCount != READ_BUFFER_SIZE) {
            break;
        }
    }

    write(clientSocket, buffer, writeCount);
    close(clientSocket);
}


