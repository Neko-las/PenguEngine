//
// Created by nicolas on 11/28/22.
//
#include <glad/glad.h>
#include "renderer.hpp"
#include "shader.hpp"
#include "buffer.hpp"

GLuint programID;
VertexBuffer vertexBuffer;

static const GLfloat data[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f,  -1.0f, 0.0f,
        0.0f,  1.0f,  0.0f,
};

void prepareRendering(){
    vertexBuffer = VertexBuffer();
    vertexBuffer.transferFloatBuffer(data);

    // 1st attribute buffer : vertices

    programID = loadShaders( "shaders/firstVertexShader.vs",
                             "shaders/firstFragmentShader.fs");

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer.id);
    glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
    );
    //glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);


}

void render(){

    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(programID);



}

void cleanUpRenderer(){
    glDeleteVertexArrays(1,&vertexBuffer.id);
    glDeleteProgram(programID);
    //lDeleteBuffers(1, &VBO);
}

