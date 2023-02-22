//
// Created by nicolas on 2/21/23.
//

#include "ElementBuffer.hpp"

ElementBuffer::ElementBuffer(unsigned size, GLuint* data) {
    id = 0;
    glGenBuffers(1,&id);
    uploadData(size,data);
}

ElementBuffer::~ElementBuffer() {
    glDeleteBuffers(1,&id);
}

void ElementBuffer::bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,id);
}

void ElementBuffer::unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}

void ElementBuffer::uploadData(unsigned int size, GLuint *data) {
    bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    unbind();
}

