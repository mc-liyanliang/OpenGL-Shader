#include "Shader_w.h"
#include "fstream"
#include "sstream"
#include "iostream"

Shader::Shader(const GLchar* vertex_Shader_path, const GLchar* fragment_Shader_path)
{
    std::string vertex_Shader_code;
    std::string fragment_Shader_code;
    if (GetShaderFromFile(vertex_Shader_path, fragment_Shader_path, &vertex_Shader_code, &fragment_Shader_code))
    {
        return;
    }
    if (LinkShader(vertex_Shader_code.c_str(), fragment_Shader_code.c_str()))
    {
        return;
    }
}

Shader::~Shader()
{

}

void Shader::Use()
{
    glUseProgram(ID);
}

void Shader::SetBool(const std::string &name, bool value) const
{
    SetInt(name, (int)value);
}

void Shader::SetInt(const std::string &name, int value) const
{
    glUniform1i(GetUniform(name), value);
}

void Shader::SetFloat(const std::string &name, float value) const
{
    glUniform1f(GetUniform(name), value);
}

void Shader::SetVec2(const std::string &name, float x, float y) const
{
    glUniform2f(GetUniform(name), x, y);
}

void Shader::SetVec2(const std::string &name, const glm::vec2 &value) const
{
    SetVec2(name, value.x, value.y);
}

void Shader::SetVec3(const std::string &name, float x, float y, float z) const
{
    glUniform3f(GetUniform(name), x, y, z);
}

void Shader::SetVec3(const std::string &name, const glm::vec3 &value) const
{
    SetVec3(name, value.x, value.y, value.z);
}

void Shader::SetVec4(const std::string &name, float x, float y, float z, float w) const
{
    glUniform4f(GetUniform(name), x, y, z, w);
}

void Shader::SetVec4(const std::string &name, const glm::vec4 &value) const
{
    SetVec4(name, value.x, value.y, value.z, value.w);
}

void Shader::SetMat2(const std::string &name, const glm::mat2 &value) const
{
    glUniformMatrix2fv(GetUniform(name), 1, GL_FALSE, &value[0][0]);
}

void Shader::SetMat3(const std::string &name, const glm::mat3 &value) const
{
    glUniformMatrix3fv(GetUniform(name), 1, GL_FALSE, &value[0][0]);
}

void Shader::SetMat4(const std::string &name, const glm::mat4 &value) const
{
    glUniformMatrix4fv(GetUniform(name), 1, GL_FALSE, &value[0][0]);
}

int Shader::GetShaderFromFile(const GLchar* vertex_Shader_path, const GLchar* fragment_Shader_path, std::string *vertex_Shader_code, std::string *fragment_Shader_code)
{
    std::ifstream vertex_Shader_file;
    std::ifstream fragment_Shader_file;
    vertex_Shader_file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    fragment_Shader_file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    try
    {
        vertex_Shader_file.open(vertex_Shader_path);
        fragment_Shader_file.open(fragment_Shader_path);
        std::stringstream vertex_Shader_stream, fragment_Shader_stream;
        vertex_Shader_stream << vertex_Shader_file.rdbuf();
        fragment_Shader_stream << fragment_Shader_file.rdbuf();
        vertex_Shader_file.close();
        fragment_Shader_file.close();
        *vertex_Shader_code = vertex_Shader_stream.str();
        *fragment_Shader_code = fragment_Shader_stream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "Load Shader File Error!" << std::endl;
        return -1;
    }
    return 0;
}

int Shader::LinkShader(const char* vertex_Shader_code, const char* fragment_Shader_code)
{
    int vertex_Shader = glCreateShader(GL_VERTEX_Shader);
    glShaderSource(vertex_Shader, 1, &vertex_Shader_code, NULL);
    glCompileShader(vertex_Shader);
    CheckCompileErrors(vertex_Shader, "VERTEX");

    int fragment_Shader = glCreateShader(GL_FRAGMENT_Shader);
    glShaderSource(fragment_Shader, 1, &fragment_Shader_code, NULL);
    glCompileShader(fragment_Shader);
    CheckCompileErrors(fragment_Shader, "FRAGMENT");

    this->ID = glCreateProgram();
    glAttachShader(ID, vertex_Shader);
    glAttachShader(ID, fragment_Shader);
    glLinkProgram(ID);
    CheckCompileErrors(ID, "PROGRAM");

    glDeleteShader(vertex_Shader);
    glDeleteShader(fragment_Shader);
    return 0;
}

int Shader::GetUniform(const std::string &name) const
{
    int position = glGetUniformLocation(ID, name.c_str());
    if (position == -1)
    {
        std::cout << "uniform " << name << " set failed!" << std::endl;
    }
    return position;
}

void Shader::CheckCompileErrors(GLuint Shader, std::string type)
{
    GLint success;
    GLchar infoLog[512];
    if (type == "PROGRAM")
    {
        glGetProgramiv(Shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(Shader, 512, NULL, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR!\n" << infoLog << std::endl;
        }
    }
    else
    {
        glGetShaderiv(Shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(Shader, 512, NULL, infoLog);
            std::cout << "ERROR::Shader::" << type << "::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
    }
}