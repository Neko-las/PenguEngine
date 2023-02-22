#include <iostream>
#include <vector>

#include "glad/glad.h"

#include "main.hpp"
//TODO: write and InputHandler
#include "input/keyboardInput.hpp"
#include "input/mouseInput.hpp"

#include "window/window.hpp"

#include "rendering/renderer.hpp"
#include "rendering/buffer/VertexArray.hpp"
#include "rendering/buffer/VertexBuffer.hpp"
#include "rendering/buffer/ElementBuffer.hpp"

#include "glm/glm.hpp"

bool isRunning = false;
GLFWwindow* windowPtr = nullptr;

int startGame(){
    isRunning = true;
    windowPtr = initWindow();

    if(initKeyboardInputListener(windowPtr) == -1){
        printf("Failed to initialize KeyboardListener\n");
    }

    if(initMouseInputListener(windowPtr) == -1){
        printf("Failed to initialize MouseListener\n");
    }
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        return -1;
    }

    run();
    return 0;
}
int endGame(){
    isRunning = false;
    return 0;
}

int run(){
    Renderer renderer = Renderer();

    GLfloat vertices[] = {
            0.5f,  0.5f, 0.0f,  // top right
            0.5f, -0.5f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f,  // bottom left
            -0.5f,  0.5f, 0.0f   // top left
    };

    GLuint indices[] = {
            0, 1, 3,  // first triangle
            1, 2, 3    // second triangle
    };

    VertexArray vertexArray = VertexArray();
    VertexBuffer vertexBuffer = VertexBuffer(sizeof(vertices),vertices);
    ElementBuffer elementBuffer = ElementBuffer(sizeof(indices),indices);


    renderer.prepareRendering(&vertexArray, &vertexBuffer, &elementBuffer);

    while(!glfwWindowShouldClose(windowPtr) && isRunning){

        renderer.render(&vertexArray);
        glfwSwapBuffers(windowPtr);
        glfwPollEvents();
    }

    renderer.cleanUpRenderer();
    return 0;
}

int main(){
    std::cout << "Hello, World!" << std::endl;
    startGame();
    destroyWindow(windowPtr);
    glfwTerminate();
}
