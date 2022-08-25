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

#ifndef RPCSERVER_H
#define RPCSERVER_H

#include <iostream>
#include <pthread.h>
#include <netinet/in.h>
#include <sys/socket.h>

class RpcServer {

private:
    int listenerSocket = -1;
    int clientSocket = -1;
    struct sockaddr_in socketAddress;
    int socketFd = -1;

    pthread_t networkThread;
    pthread_mutex_t mutex;

public:
    RpcServer();

    ~RpcServer();

    void wait();

    static void *ThreadProc(void *data);

    void socketListen();
};


#endif
