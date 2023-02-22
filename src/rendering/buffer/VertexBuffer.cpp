//
// Created by nicolas on 2/21/23.
//

#include "VertexBuffer.hpp"

VertexBuffer::VertexBuffer(unsigned size, GLfloat* data) {
    id = 0;
    glGenBuffers(1,&id);
    uploadData(size,data);
}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1,&id);
}

void VertexBuffer::bind() {
    glBindBuffer(GL_ARRAY_BUFFER,id);
}

void VertexBuffer::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER,0);
}

void VertexBuffer::uploadData(unsigned size, GLfloat *data) {
    bind();
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    unbind();
}

