#include <fstream>
#include "Shader.h"

std::string Shader::lastCompileError() const
{
    return _lastCompileError;
}

ShaderType Shader::shaderType() const
{
    return _type;
}

bool Shader::compileStatus() const
{
    return _compiledStatus;
}

std::string Shader::loadShaderSource(const boost::filesystem::path &path)
{
    std::fstream file(path.string(), std::ios_base::in);

    if (!file.is_open())
        throw std::logic_error("Cannot open file in path: " + path.string());

    std::string shaderSource;
    while (!file.eof()) {
        std::string buffer;
        std::getline(file, buffer);
        shaderSource += buffer + '\n';
    }

   // TODO: Пофиксить пропуск пробельных символов при чтении файла при помощи
   // TODO: итератора
   /* std::istream_iterator<char> is(file);
   const int buffer_size = boost::filesystem::file_size(path);
   std::string shaderSource;
   shaderSource.resize(buffer_size);
   std::copy(is, std::istream_iterator<char>(), shaderSource.begin());*/

    return std::move(shaderSource);
}

bool Shader::compileShader(const std::string &source, ShaderType type)
{
    if (!type)
        throw std::logic_error("Unknown shader type");

    const char * rawSource = source.data();
    _shader = glCreateShader(type);
    glShaderSource(_shader, 1, &rawSource, NULL);
    glCompileShader(_shader);

    int compileStatus;
    glGetShaderiv(_shader, GL_COMPILE_STATUS, &compileStatus);

    if (!compileStatus) {
        const int logBufferSize = 512;
        char buffer[logBufferSize];
        glGetShaderInfoLog(_shader, logBufferSize, NULL, buffer);
        _lastCompileError = buffer;

        return false;
    }

    compileStatus = true;
    return true;
}

bool Shader::compileFromSource(const boost::filesystem::path &path, ShaderType type)
{
    const std::string shaderSource = loadShaderSource(path);
    return compileShader(shaderSource, type);
}