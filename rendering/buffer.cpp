//
// Created by nicolas on 11/28/22.
//

#include "buffer.hpp"

VertexArrayObject::VertexArrayObject() {
    generateAndBindVertexArray();
}

void VertexArrayObject::generateAndBindVertexArray() {
    glGenVertexArrays(1, &id);
    glBindVertexArray(id);
}

VertexBuffer::VertexBuffer() {
    generateAndBindBuffer();
}

void VertexBuffer::generateAndBindBuffer() {
    // Generate 1 buffer
    glGenBuffers(1, &id);
    // Bind the Buffer
    glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VertexBuffer::transferFloatBuffer(const GLfloat* data) {
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
}

void VertexBuffer::bindBuffer() const{
    glBindBuffer(GL_ARRAY_BUFFER, id);
}


