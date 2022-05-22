//
// Created by Tan Li Yuan on 21/5/22.
//

#include "Shader.h"
//#include <filesystem>

Shader::Shader() {
    shaderID = 0;
}

void Shader::CreateFromFiles(const char* vertexLocation, const char* fragmentLocation) {
    std::string vertexString = ReadFile(vertexLocation);
    std::string fragmentString = ReadFile(fragmentLocation);
    const char* vertexCode = vertexString.c_str();
    const char* fragmentCode = fragmentString.c_str();

    CompileShader(vertexCode, fragmentCode);
}

std::string Shader::ReadFile(const char* fileLocation) {
    std::string content;
    std::ifstream fileStream(fileLocation, std::ios::in);

//    fileDir is located in cmake-build-debug: Assignment_0_mac_cleaned/cmake-build-debug"
//    std::cout << std::__fs::filesystem::current_path() << std::endl;

    if (!fileStream.is_open()) {
        std::cout << "Failed to read " << fileLocation << "! File doesn't exist." << std::endl;
        return "";
    }

    std::string line = "";
    while (!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    return content;
}

void Shader::CompileShader(const char* vertexCode, const char* fragmentCode) {
    // link shaders
    shaderID = glCreateProgram();

    if (!shaderID) {
        std::cout << "Error creating shader program!" << std::endl;
        return;
    }

    AddShader(shaderID, vertexCode, GL_VERTEX_SHADER);
    AddShader(shaderID, fragmentCode, GL_FRAGMENT_SHADER);

    GLint result = 0;
    GLchar eLog[1024] = { 0 };

    glLinkProgram(shaderID);

    // check for linking errors
    glGetProgramiv(shaderID, GL_LINK_STATUS, &result);
    if (!result) {
        glGetProgramInfoLog(shaderID, sizeof(eLog), NULL, eLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << eLog << std::endl;
        return;
    }
}

void Shader::AddShader(GLuint theProgram, const char *shaderCode, GLenum shaderType) {
    // build and compile our shader program
    // ------------------------------------
    // vertex/fragment shader
    GLuint theShader = glCreateShader(shaderType);

    const GLchar* theCode[1];
    theCode[0] = shaderCode;

    GLint codeLength[1];
    codeLength[0] = static_cast<int>(strlen(shaderCode));

    glShaderSource(theShader, 1, theCode, codeLength);
    glCompileShader(theShader);

    // check for shader compile errors
    GLint success = 0;
    GLchar eLog[1024] = { 0 };

    glGetShaderiv(theShader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetProgramInfoLog(theShader, sizeof(eLog), NULL, eLog);
        std::cout << "ERROR::SHADER::" << shaderType << "::COMPILATION_FAILED\n" << eLog << std::endl;
        return;
    }
    glAttachShader(theProgram, theShader);
}

void Shader::UseShader() {
    glUseProgram(shaderID);
}

void Shader::ClearShader() {
    if (shaderID != 0) {
        glDeleteProgram(shaderID);
        shaderID = 0;
    }
}

Shader::~Shader() {
    ClearShader();
}