#include "shader.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

void shader::use()
{
    glUseProgram(this->ID);
}

shader::shader(const char* vertexpath, const char* fragmentpath)
{
    //1. retrieve the shader source code from the filepaths
    std::string vertexCode, fragmentCode;
    std::ifstream vShaderFile, fShaderFile;

    //create errors if file reading failed
    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        //open files
        vShaderFile.open(vertexpath);
        fShaderFile.open(fragmentpath);
        std::stringstream vShaderStream, fShaderStream;

        //read file's buffer content into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        //close files
        vShaderFile.close();
        fShaderFile.close();

        //convert streams into strings
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch(std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
    }

    //convert into usable c string
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    //2. compile shaders
    unsigned int vertex, fragment;
    int success;
    char infoLog[512];

    //vertex shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);

    //check if compile was successful
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //fragment shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);

    //check if compile was successful
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //shader program
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);

    //check if program creation was successful
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    //delete shaders after use
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}


//uniform functions
void shader::setBool(const std::string &name, bool value)
{
    glUniform1i(glGetUniformLocation(this->ID, name.c_str()), int(value));
}

void shader::setInt(const std::string &name, int value)
{
    glUniform1i(glGetUniformLocation(this->ID, name.c_str()), value);
}

void shader::setFloat(const std::string &name, float value)
{
    glUniform1f(glGetUniformLocation(this->ID, name.c_str()), value);
}

void shader::setVec2(const std::string &name, const glm::vec2 &value)
{
    glUniform2fv(glGetUniformLocation(this->ID, name.c_str()), 1, &value[0]);
}

void shader::setVec2(const std::string &name, float x, float y)
{
    glUniform2f(glGetUniformLocation(this->ID, name.c_str()), x, y);
}

void shader::setVec3(const std::string &name, const glm::vec3 &value)
{
    glUniform3fv(glGetUniformLocation(this->ID, name.c_str()), 1, &value[0]);
}

void shader::setVec3(const std::string &name, float x, float y, float z)
{
    glUniform3f(glGetUniformLocation(this->ID, name.c_str()), x, y, z);
}

void shader::setVec4(const std::string &name, const glm::vec4 &value)
{
    glUniform4fv(glGetUniformLocation(this->ID, name.c_str()), 1, &value[0]);
}

void shader::setVec4(const std::string &name, float x, float y, float z, float w)
{
    glUniform4f(glGetUniformLocation(this->ID, name.c_str()), x, y, z, w);
}

void shader::setMat2(const std::string &name, const glm::mat2 &value)
{
    glUniformMatrix2fv(glGetUniformLocation(this->ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

void shader::setMat3(const std::string &name, const glm::mat3 &value)
{
    glUniformMatrix3fv(glGetUniformLocation(this->ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

void shader::setMat4(const std::string &name, const glm::mat4 &value)
{
    glUniformMatrix4fv(glGetUniformLocation(this->ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}