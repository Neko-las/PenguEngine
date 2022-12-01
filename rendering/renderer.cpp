//
// Created by nicolas on 11/28/22.
//
#include <glad/glad.h>
#include "renderer.hpp"
#include "shader.hpp"
#include "buffer.hpp"

GLfloat data[] = {
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
    vertexBuffer.bindVertexBuffer();

    vertexBuffer.transferFloatBuffer(data,sizeof(data));

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)nullptr);
    glEnableVertexAttribArray(0);

    // unbind VertexBuffer
    vertexBuffer.unbindVertexBuffer();

    // Unbind VertexArray
    vertexArrayObject.unbindVertexArray();
}

void Renderer:: render() const{

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // draw our first triangle
    glUseProgram(programID);
    vertexArrayObject.bindVertexArray();
    glDrawArrays(GL_TRIANGLES, 0, 3);

}

void Renderer::cleanUpRenderer(){
    glDeleteProgram(programID);
    vertexBuffer.~VertexBuffer();
    vertexArrayObject.~VertexArrayObject();
}

