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

#ifndef RPCTREAD_H
#define RPCTREAD_H


#include <thread>

class RpcTread {
    RpcTread() = delete;

    RpcTread(const std::string &threadName, const std::function<void()> &callback);

    ~RpcTread();

    void wait();

private:
    std::thread rpcThread;
    std::string threadName;
};


#endif
