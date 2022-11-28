//
// Created by nicol on 27/11/2022.
//

#include <iostream>
#include "keyboardInput.hpp"
#include "../main.hpp"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if(action == GLFW_PRESS){
        switch(key){
            case (GLFW_KEY_E):{
                //end Game!
                std::cout << "E was pressed!\n";
                endGame();

            }
        }
    }
}

int initKeyboardInputListener(GLFWwindow* windowPtr){

    glfwSetKeyCallback(windowPtr, key_callback);

    if(windowPtr == nullptr){
        return -1;
    }
    return 0;
}
