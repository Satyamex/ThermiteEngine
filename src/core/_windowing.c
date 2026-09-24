#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "core/_windowing.h"

GLFWwindow* window = NULL;

int window_init()
{
    if (!glfwInit())
        return -1;
    return 0;
}

void window_onframebuffersize_changed(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int window_createwindow(GameWindow* gamewindow)
{
    window = glfwCreateWindow(gamewindow->width, gamewindow->height, gamewindow->title, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        return -1;

    glViewport(0, 0, gamewindow->width, gamewindow->height);
    glfwSetFramebufferSizeCallback(window, window_onframebuffersize_changed);

    return 0;
}

void window_handlewindow(void)
{
    glClearColor(0.12f, 0.12f, 0.12f, 1.0f);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}