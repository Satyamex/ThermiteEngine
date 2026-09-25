#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "core/_renderer.h"
#include "core/_windowing.h"
#include "core/_time.h"

void renderer_draw(void)
{
    float trisverts[9] = {-0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f};

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(trisverts), trisverts, GL_STATIC_DRAW);

    glClearColor(0.12f, 0.12f, 0.12f, 1.0f);

    while (!glfwWindowShouldClose(window))
    {
        /* render shit */

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        /* process event bs */

        time_lasttime = time_gettime();
        glfwPollEvents();
    }

    glfwTerminate();
}