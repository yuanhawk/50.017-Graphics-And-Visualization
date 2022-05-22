//
// Created by Tan Li Yuan on 21/5/22.
//

#include <glad/glad.h>

#include <iostream>
#include <fstream>

class Shader {
public:
    Shader();

    void CreateFromFiles(const char* vertexLocation, const char* fragmentLocation);

    std::string ReadFile(const char* fileLocation);

    void UseShader();
    void ClearShader();

    ~Shader();

private:
    GLuint shaderID;
    char *vertexShaderSource;

    void CompileShader(const char* vertexCode, const char* fragmentCode);
    void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);
};
