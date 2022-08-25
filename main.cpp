#include <iostream>
#include <cstring>
#include "core/RpcServer.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    auto rpcServer = new RpcServer();
    rpcServer->wait();

    delete rpcServer;

    return 0;
}
