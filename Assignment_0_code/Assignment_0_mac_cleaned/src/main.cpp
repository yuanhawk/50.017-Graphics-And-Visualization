////////////////////////////////////////////////////////////////////////
//
//
//  Assignment 0 of SUTD Course 50.017 (May-Aug Term, 2021)
//
//    Rendering a Triangle
//
//  2021-May-20
//  Rewritten by: Tan Li Yuan
//
////////////////////////////////////////////////////////////////////////

#include <glad/glad.h>

#include <vector>

#include "Window.h"
#include "Shader.h"
#include "Mesh.h"

//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

std::vector<Mesh*> meshList;
std::vector<Shader> shaderList;

// vertex shader source
// ------------------------------
static const char *vertexShaderSource = "../Shaders/shader.vert";

// fragment shader source
// ------------------------------
static const char *fragmentShaderSource = "../Shaders/shader.frag";

Window mainWindow;

void CreateObjects() {

    GLfloat vertices[] = {
            // positions         // colors
            -0.5f, -0.5f, 0.0f,  0.4f, 1.0f, 0.4f,  // bottom left
            0.5f, -0.5f, 0.0f,  0.4f, 1.0f, 0.4f,  // bottom right
            0.0f,  0.5f, 0.0f,  0.4f, 1.0f, 0.4f   // top
    };

    Mesh *obj1 = new Mesh();
    obj1 -> CreateMesh(vertices, 18);
    meshList.push_back(obj1);
}

void CreateShaders() {
    Shader *shader1 = new Shader();
    shader1 -> CreateFromFiles(vertexShaderSource, fragmentShaderSource);
    shaderList.push_back(*shader1);
}

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    mainWindow = Window(SCR_WIDTH, SCR_HEIGHT, "Assignment 0 - Hello World");
    mainWindow.initialize();

    CreateObjects();
    CreateShaders();

     // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
     // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
     // glBindVertexArray(0);

     // as we only have a single shader, we could also just activate our shader once beforehand if we want to
     //glUseProgram(shaderProgram);

    shaderList[0].UseShader();

   
    // render loop
    // -----------
    while (!mainWindow.getShouldClose()) {

        // Clear window
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        meshList[0] -> RenderMesh();

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        mainWindow.swapBuffers();
        glfwPollEvents();
    }

    return 0;
}




