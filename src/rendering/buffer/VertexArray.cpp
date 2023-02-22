//
// Created by nicolas on 2/21/23.
//

#include <iostream>
#include "VertexArray.hpp"

VertexArray::VertexArray() {
    id = 0;
    glGenVertexArrays(1,&id);
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1,&id);
}

void VertexArray::setLayout(VertexBuffer* vertexBuffer, ElementBuffer* elementBuffer) {
    bind();

    elementBuffer->bind();
    vertexBuffer->bind();

    //set vertex attribs
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)nullptr);
    glEnableVertexAttribArray(0);
    // unbind Vertex Buffer
    vertexBuffer->unbind();

    // Unbind VertexArray
    unbind();

    elementBuffer->unbind();
}

void VertexArray::bind() {
    glBindVertexArray(id);
}

void VertexArray::unbind() {
    glBindVertexArray(0);
}

