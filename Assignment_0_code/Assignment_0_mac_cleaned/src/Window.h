//
// Created by Tan Li Yuan on 19/5/22.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <cstdio>

class Window {
public:
    Window();

    Window(GLint windowWidth, GLint windowHeight, std::string title);
    int initialize();

    bool getShouldClose() { return glfwWindowShouldClose(window); }

    void swapBuffers() { glfwSwapBuffers(window); }

    ~Window();


private:
    GLFWwindow *window;
    GLint width, height;
    std::string title;

    void createCallbacks();

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    static void handleKeys(GLFWwindow* window, int key, int code, int action, int mode);
};
