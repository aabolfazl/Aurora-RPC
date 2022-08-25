cmake_minimum_required(VERSION 3.22)
project(aRPC)

set(CMAKE_CXX_STANDARD 14)

add_executable(aRPC
        main.cpp
        core/RpcServer.cpp
        core/RpcServer.h
        core/TcpSocket.cpp
        core/TcpSocket.h
        core/Define.h
        core/RpcTread.cpp
        core/RpcTread.h
        core/ByteBuffer.cpp
        core/ByteBuffer.h
        core/SocketConnection.cpp
        core/SocketConnection.h
        )

target_link_libraries(aRPC -lpthread)
