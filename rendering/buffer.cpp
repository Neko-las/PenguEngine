//
// Created by nicolas on 11/28/22.
//
#include <iostream>
#include "buffer.hpp"

VertexArrayObject::VertexArrayObject() {
    generateVertexArray();
}

void VertexArrayObject::generateVertexArray() {
    glGenVertexArrays(1, &id);
}

void VertexArrayObject::bindVertexArray() const {
    glBindVertexArray(id);
}

void VertexArrayObject::unbindVertexArray() {
    glBindVertexArray(0);
}

VertexBuffer::VertexBuffer() {
    generateBuffer();
}

void VertexBuffer::generateBuffer() {
    // Generate 1 buffer
    glGenBuffers(1, &id);
}

void VertexBuffer::transferFloatBuffer(GLfloat* data,long size) {
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void VertexBuffer::bindVertexBuffer() const{
    glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VertexBuffer::unbindVertexBuffer() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}


