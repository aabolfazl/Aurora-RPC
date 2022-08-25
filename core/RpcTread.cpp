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

#include "RpcTread.h"

RpcTread::RpcTread(const std::string &threadName, const std::function<void()> &callback) {
    this->threadName = threadName;
    rpcThread = std::thread(callback);
}

RpcTread::~RpcTread() {

}

void RpcTread::wait() {
    if (rpcThread.joinable()) {
        rpcThread.join();
    }
}
