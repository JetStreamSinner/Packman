//
// Created by alex on 01.06.2020.
//
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Shader.h"
#include "ShaderProgram.h"

const char * vertexShaderSource =
"#version 330 core\n"\
"layout (location = 0) in vec3 aPos;\n"\
"void main()\n"\
"{\n"\
"    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"\
"}\n";

const char * fragmentShaderSource =
        "#version 330 core\n"\
        "out vec4 FragColor;\n"\
        "void main()\n"\
        "{\n"\
        "FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"\
        "}\n";


int main(int argc, char * argv[])
{

    GLFWwindow * window = nullptr;
    if (!glfwInit())
        return -1;
    window = glfwCreateWindow(640, 480, "Hello world", NULL, NULL);
    if (!window){
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if(glewInit() != GLEW_OK)
        std::cout << "Error" << std::endl;


    Shader vertexShader;
    const std::string vertexShaderSourcesPath = "/home/alex/Project/Packman/PackmanGame/Shaders/VertexShader.gsl";
    vertexShader.compileFromSource(vertexShaderSourcesPath, VertexShader);

    Shader fragmentShader;
    const std::string fragmentShaderSourcesPath = "/home/alex/Project/Packman/PackmanGame/Shaders/FragmentShader.gsl";
    fragmentShader.compileFromSource(fragmentShaderSourcesPath, FragmentShader);

    std::cout << "Vertex shader error: " << vertexShader.lastCompileError() << std::endl;
    std::cout << "Fragment shader error: " << fragmentShader.lastCompileError() << std::endl;
    std::cout << "Error: " << glGetError() << std::endl;

    ShaderProgram program;
    program.attachShader(vertexShader);
    program.attachShader(fragmentShader);
    program.link();

    std::cout << "Vertex shader compile status: " << (vertexShader.compileStatus() ? "true" : "false") << std::endl;
    std::cout << "Fragment shader compile status: " << (fragmentShader.compileStatus() ? "true" : "false") << std::endl;
    std::cout << "Shader program linkage status: " << (program.linkageStatus() ? "true" : "false") << std::endl;

    float position[12] = {
            0.5f,  0.5f, 0.0f,  // верхняя правая
            0.5f, -0.5f, 0.0f,  // нижняя правая
            -0.5f, -0.5f, 0.0f,  // нижняя левая
            -0.5f,  0.5f, 0.0f   // верхняя левая
    };

    unsigned int indices[] = {  // помните, что мы начинаем с 0!
            0, 1, 3,   // первый треугольник
            1, 2, 3    // второй треугольник
    };

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);



    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), position, GL_STATIC_DRAW);

    unsigned  int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    while(!glfwWindowShouldClose(window)) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        program.bindProgram();
        glBindVertexArray(VAO);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}