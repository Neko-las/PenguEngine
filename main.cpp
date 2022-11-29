#include <iostream>
#include <vector>
#include <glad/glad.h>

#include "main.hpp"
//TODO: write and InputHandler
#include "input/keyboardInput.hpp"
#include "input/mouseInput.hpp"
#include "window/window.hpp"
#include "rendering/renderer.hpp"
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

    run();
    return 0;
}
int endGame(){
    isRunning = false;
    return 0;
}

int run(){

    //prepareRendering();

    while(!glfwWindowShouldClose(windowPtr) && isRunning){

        //render();
        glfwSwapBuffers(windowPtr);
        glfwPollEvents();
    }

    cleanUpRenderer();
    destroyWindow(windowPtr);
    glfwTerminate();

    return 0;
}

int main(){
    std::cout << "Hello, World!" << std::endl;
    startGame();
}
