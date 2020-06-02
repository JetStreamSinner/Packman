#ifndef _SHADER_
#define _SHADER_

#include <memory>
#include <GL/glew.h>
#include <boost/filesystem.hpp>

enum ShaderType
{
    VertexShader = GL_VERTEX_SHADER,
    FragmentShader = GL_FRAGMENT_SHADER,
    None = 0
};

class ShaderProgram;

class Shader
{
    friend ShaderProgram;
public:
    Shader() : _shader(0), _type(ShaderType::None), _compiledStatus(false) { }
    Shader(const Shader &rhs) = delete;
    Shader& operator=(const Shader &rhs) = delete;

    bool compileShader(const std::string &source, ShaderType type);
    bool compileFromSource(const boost::filesystem::path &path, ShaderType type);

    bool compileStatus() const;
    std::string lastCompileError() const;
    ShaderType shaderType() const;
private:
    std::string loadShaderSource(const boost::filesystem::path &path);

    std::string _lastCompileError;
    bool _compiledStatus;

    unsigned int _shader;
    ShaderType _type;
};

#endif