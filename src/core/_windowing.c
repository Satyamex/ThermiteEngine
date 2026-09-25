#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "core/_windowing.h"

GLFWwindow* window = NULL;

int window_init()
{
    if (!glfwInit())
        return -1;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
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