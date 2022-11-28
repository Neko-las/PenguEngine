#include <iostream>
#include <vector>
#include <glad/glad.h>

#include "main.hpp"
#include "input/keyboardInput.hpp"
#include "input/mouseInput.hpp"
#include "window/window.hpp"


//#externalLibraries "glm/glm.hpp"


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

    while(!glfwWindowShouldClose(windowPtr) && isRunning){
        glClearColor(0.8f,0.2f,0.2f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(windowPtr);
        glfwPollEvents();
    }

    destroyWindow(windowPtr);
    glfwTerminate();

    return 0;
}

int main(){
    std::cout << "Hello, World!" << std::endl;
    startGame();
}
