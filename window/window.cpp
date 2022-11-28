//
// Created by nicol on 28/11/2022.
//
#include <glad/glad.h>
#include <iostream>
#include "window.hpp"

GLFWwindow* initWindow(){

    int windowWith = 1280;
    int windowHeight = 720;
    //TODO::fix char*
    const char* windowTitle = "PenguGame";

    //initialize glfw
    if(!glfwInit()){
        std::cout << "Failed to initialize GLFW!\n";
    }

    //tell window that glfw 3.3 is beeing used
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);

    //... ? no clue ? TODO::lookup that
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_COMPAT_PROFILE);

    int nrMonitors;

    GLFWmonitor* primaryMonitor = nullptr;
    //TODO::Error handling
    GLFWmonitor** monitors = glfwGetMonitors(&nrMonitors);

    //for fullscreen
    //GLFWwindow* primaryMonitor = glfwGetPrimaryMonitor();
    //GLFWwindow* windowPtr = glfwCreateWindow(windowWith,windowHeight,windowTitle,primaryMonitor, nullptr);
    GLFWwindow* windowPtr = glfwCreateWindow(windowWith,windowHeight,windowTitle,monitors[1], nullptr);

    if(windowPtr == nullptr){
        std::cout << "Failed to create Window with GLFW!\n";
        glfwTerminate();
        return nullptr;
    }

    std::cout << "Success in creating a Window\n";

    glfwMakeContextCurrent(windowPtr);
    gladLoadGL();
    glViewport(0,0,windowWith,windowHeight);


    std::cout << "This works!\n";

    return windowPtr;
}

void destroyWindow(GLFWwindow* windowPtr){
    if(windowPtr != nullptr){
        std::cout << "Window is being destroyed\n";
        glfwDestroyWindow(windowPtr);
    }
}




