#ifndef _SHADER_
#define _SHADER_

#include <memory>
#include <boost/filesystem.hpp>

enum class ShaderType
{
    VertexShader,
    FragmentShader
};

class Shader
{
public:
    bool compileShader(const std::string &source);
    bool compileFromSource(const boost::filesystem::path &path);
private:
    u
};

#endif