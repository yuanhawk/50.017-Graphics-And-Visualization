////////////////////////////////////////////////////////////////////////
//
//
//  Assignment 0 of SUTD Course 50.017 (May-Aug Term, 2021)
//
//    Rendering a Triangle
//
//  2021-May-20
//
//
////////////////////////////////////////////////////////////////////////


#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>

#include "Window.h"
#include "Shader.h"

//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

std::vector<Shader> shaderList;

// vertex shader source
// ------------------------------
static const char *vertexShaderSource = "../Shaders/shader.vert";

// fragment shader source
// ------------------------------
static const char *fragmentShaderSource = "../Shaders/shader.frag";

Window mainWindow;

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

    CreateShaders();

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    GLfloat vertices[] = {
        // positions         // colors
        0.5f, -0.5f, 0.0f,  0.4f, 1.0f, 0.4f,  // bottom right
       -0.5f, -0.5f, 0.0f,  0.4f, 1.0f, 0.4f,  // bottom left
        0.0f,  0.5f, 0.0f,  0.4f, 1.0f, 0.4f   // top
    };

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    // glBindVertexArray(0);

    // as we only have a single shader, we could also just activate our shader once beforehand if we want to 
//    glUseProgram(shaderProgram);

    shaderList[0].UseShader();
   
    // render loop
    // -----------
    while (!mainWindow.getShouldClose())
    {
        // input
        // -----
//        processInput(window);

        // render
        // ------
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(VAO);

        // render the triangle
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // render the triangle edges
        //glDrawArrays(GL_LINE_LOOP, 0, 3);

        // render the triangle vertices
        //glEnable(GL_PROGRAM_POINT_SIZE); 
        //glPointSize(50.0);
        //glDrawArrays(GL_POINTS, 0, 3);


        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        mainWindow.swapBuffers();
        glfwPollEvents();
    }


    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
//    glDeleteProgram(shaderProgram);

    return 0;
}




