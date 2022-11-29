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

void VertexArrayObject::bindVertexArray() {
    glBindVertexArray(id);
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

void VertexBuffer::bindBuffer() const{
    glBindBuffer(GL_ARRAY_BUFFER, id);
}


