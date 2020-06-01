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

class Shader
{
public:
    Shader() : _shader(0), _type(ShaderType::None) { }
    Shader(const Shader &rhs) = delete;
    Shader& operator=(const Shader &rhs) = delete;

    Shader(const Shader &&lhs) noexcept;
    Shader& operator=(const Shader &&lhs);

    bool compileShader(const std::string &source, ShaderType type);
    bool compileFromSource(const boost::filesystem::path &path, ShaderType type);
private:
    std::string loadShaderSource(const boost::filesystem::path &path);

    unsigned int _shader;
    ShaderType _type;
};

#endif