//
// Created by nicolas on 11/28/22.
//
#include <glad/glad.h>
#include <iostream>
#include "renderer.hpp"
#include "shader.hpp"
#include "buffer.hpp"

static const GLfloat data[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f,  -1.0f, 0.0f,
        0.0f,  1.0f,  0.0f,
};
GLfloat vertices[] = {
        // first triangle
        -0.9f, -0.5f, 0.0f,  // left
        -0.0f, -0.5f, 0.0f,  // right
        -0.45f, 0.5f, 0.0f,  // top
        // second triangle
        0.0f, -0.5f, 0.0f,  // left
        0.9f, -0.5f, 0.0f,  // right
        0.45f, 0.5f, 0.0f   // top
};

Renderer::Renderer() {
    //do nothing
    programID = 0;
}

void Renderer::prepareRendering(){

    programID = loadShaders( "shaders/firstVertexShader.vs",
                             "shaders/firstFragmentShader.fs");

    vertexArrayObject = VertexArrayObject();
    vertexBuffer = VertexBuffer();

    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    vertexArrayObject.bindVertexArray();
    vertexBuffer.bindBuffer();

    vertexBuffer.transferFloatBuffer(vertices,sizeof(vertices));

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)nullptr);
    glEnableVertexAttribArray(0);

    // unbind VertexBuffer
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Unbind VertexArray
    glBindVertexArray(0);
    //TODO create unbind functions
}

void Renderer:: render() const{

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // draw our first triangle
    glUseProgram(programID);
    glBindVertexArray(vertexArrayObject.id);
    glDrawArrays(GL_TRIANGLES, 0, 6);

}

void Renderer::cleanUpRenderer(){

    glDeleteBuffers(1,&vertexBuffer.id);
    glDeleteVertexArrays(1,&vertexArrayObject.id);
    glDeleteProgram(programID);
    vertexBuffer.~VertexBuffer();
}

