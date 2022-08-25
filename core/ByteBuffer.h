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

#ifndef BYTEBUFFER_H
#define BYTEBUFFER_H

#include <cstdint>
#include <cstdlib>
#include <memory.h>
#include <iostream>

class ByteBuffer {
public:
    uint32_t length = 0;
    uint8_t *bytes = nullptr;

    ByteBuffer();

    ByteBuffer(uint32_t len);

    ByteBuffer(ByteBuffer *buffer);

    ByteBuffer(uint8_t *buffer, uint32_t len);

    void reallocate(uint32_t len);

    ~ByteBuffer();
};

#endif
