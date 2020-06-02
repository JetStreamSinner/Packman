//
// Created by alex on 01.06.2020.
//
#include <iostream>
#include <memory>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Renderer.h"

int main(int argc, char * argv[])
{
    const int staticWidth = 800;
    const int staticHeight = 600;
    const std::string windowTitle = "Packman";

    GLFWwindow * window = nullptr;
    if (!glfwInit())
        return -1;
    window = glfwCreateWindow(staticWidth, staticHeight, windowTitle.c_str(), NULL, NULL);
    glfwSetWindowSizeLimits(window, staticWidth, staticHeight, staticWidth, staticHeight);

    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);


    if(glewInit() != GLEW_OK)
        std::cout << "Error" << std::endl;

    std::shared_ptr<GameModel> model = std::make_shared<GameModel>();
    Renderer renderer(model);

    while(!glfwWindowShouldClose(window)) {
        renderer.render();

        int windowWidth = 0;
        int windowHeight = 0;
        glfwGetFramebufferSize(window, &windowWidth, &windowHeight);
        glViewport(0, 0, windowWidth, windowHeight);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}