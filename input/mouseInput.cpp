//
// Created by nicol on 27/11/2022.
//

#include <iostream>

#include "mouseInput.hpp"

int initMouseInputListener(GLFWwindow* windowPtr){
    if(windowPtr == nullptr){
        return -1;
    }
    glfwSetCursorPosCallback(windowPtr, cursor_position_callback);
    glfwSetScrollCallback(windowPtr, scroll_callback);

    return 0;
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos){
    //printf("xpos: %f ypos: %f\n",(float)xpos,(float)ypos);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset){
    //printf("xoffset: %f yoffsets: %f\n",(float)xoffset,(float)yoffset);
}