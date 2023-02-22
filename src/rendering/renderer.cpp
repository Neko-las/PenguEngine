//
// Created by nicolas on 11/28/22.
//
#include "glad/glad.h"
#include <iostream>
#include "renderer.hpp"
#include "shader/shader.hpp"

#include "buffer/VertexArray.hpp"
#include "buffer/ElementBuffer.hpp"

Renderer::Renderer() {
    //do nothing
    programID = 0;
    program2ID = 0;
}

void Renderer::prepareRendering(VertexArray *vertexArray, VertexBuffer *vertexBuffer, ElementBuffer *elementBuffer) {

    std::cout << "prepare rendering\n";
    programID = loadShaders( "shaders/firstVertexShader.vs",
                             "shaders/firstFragmentShader.fs");

    vertexArray->setLayout(vertexBuffer, elementBuffer);

    // unbind Element Buffer
    elementBuffer->unbind();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
}


void Renderer::render(VertexArray *vertexArray) const{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // draw our first triangle

    glUseProgram(programID);

    vertexArray->bind();

    //glDrawArrays(GL_TRIANGLES,0,6);
    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,nullptr);

    vertexArray->unbind();
}

void Renderer::cleanUpRenderer(){
    glDeleteProgram(programID);
}

