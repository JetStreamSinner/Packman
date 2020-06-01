#include <fstream>
#include <iostream>

#include "Shader.h"

Shader::Shader(const Shader &&lhs) noexcept
{

}

Shader& Shader::operator=(const Shader &&lhs)
{

}

std::string Shader::loadShaderSource(const boost::filesystem::path &path)
{
    std::fstream file(path.string(), std::ios_base::in);

    if (!file.is_open())
        throw std::logic_error("Cannot open file in path: " + path.string());

    const int buffer_size = boost::filesystem::file_size(path);

    std::istream_iterator<char> is(file);
    std::string shaderSource;
    shaderSource.resize(buffer_size);
    std::copy(is, std::istream_iterator<char>(), shaderSource.begin());

    return std::move(shaderSource);
}

bool Shader::compileShader(const std::string &source, ShaderType type)
{
    if (!type)
        throw std::logic_error("Unknow shader type");

    const char * rawSource = source.data();
    _shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(_shader, 1, &rawSource, NULL);
    glCompileShader(_shader);

    int compileStatus;
    glGetShaderiv(_shader, GL_COMPILE_STATUS, &compileStatus);

    if (!compileStatus) {
        const int logBufferSize = 512;
        char buffer[logBufferSize];
        glGetShaderInfoLog(_shader, logBufferSize, NULL, buffer);
        std::cout << "SHADER COMPILATION ERROR:" << buffer << std::endl;
    }
    return true;
}

bool Shader::compileFromSource(const boost::filesystem::path &path, ShaderType type)
{
    const std::string shaderSource = loadShaderSource(path);
    return compileShader(shaderSource, type);
}