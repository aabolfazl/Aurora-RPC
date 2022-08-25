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

#include "ByteBuffer.h"

ByteBuffer::ByteBuffer() {
    bytes = nullptr;
    length = 0;
}

ByteBuffer::ByteBuffer(uint32_t len) {
    bytes = new uint8_t[len];
    length = len;
}

ByteBuffer::ByteBuffer(ByteBuffer *buffer) {
    bytes = new uint8_t[buffer->length];
    length = buffer->length;
    memcpy(bytes, buffer->bytes, length);
}

ByteBuffer::ByteBuffer(uint8_t *buffer, uint32_t len) {
    bytes = new uint8_t[len];
    length = len;
    memcpy(bytes, buffer, length);
}
void ByteBuffer::reallocate(uint32_t len) {
    if (bytes != nullptr) {
        delete[] bytes;
        bytes = nullptr;
    }
    bytes = new uint8_t[len];
    length = len;
}

ByteBuffer::~ByteBuffer() {
    if (bytes != nullptr) {
        delete[] bytes;
        bytes = nullptr;
    }
}
