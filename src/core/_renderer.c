#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "core/_renderer.h"
#include "core/_windowing.h"
#include "core/_time.h"

static GLuint create_shader(const char* vertshadersource, const char* fragshadersource)
{
    GLuint program = glCreateProgram();
    GLuint vertsh = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragsh = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertsh, 1, &vertshadersource, NULL);
    glShaderSource(fragsh, 1, &fragshadersource, NULL);
    glCompileShader(vertsh);
    glCompileShader(fragsh);
    glAttachShader(program, vertsh);
    glAttachShader(program, fragsh);
    glLinkProgram(program);
    glValidateProgram(program);
    glDeleteShader(vertsh);
    glDeleteShader(fragsh);

    GLint result;
    glGetShaderiv(vertsh, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
        printf("failed to compile vertsh.");
    glGetShaderiv(fragsh, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
        printf("failed to compile fragsh.");
    return program;
}

void renderer_draw(void)
{
    float trisverts[9] = {-0.5f, -0.5f, 0.0f, 0.5f, 0.5f, -0.5f};

    GLuint vbo, vao;
    glGenBuffers(1, &vbo);
    glGenVertexArrays(1, &vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBindVertexArray(vao);
    glBufferData(GL_ARRAY_BUFFER, sizeof(trisverts), trisverts, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (const void*)0);

    const char* vertsh =
        "#version 330 core\n"
        "layout(location = 0) in vec4 position;"
        "void main()\n"
        "{\n"
        "   gl_Position = position;\n"
        "}\n";
    const char* fragsh =
        "#version 330 core\n"
        "layout(location = 0) out vec4 color;"
        "void main()\n"
        "{\n"
        "   color = vec4(0.88, 0.88, 0.88, 1.0);\n"
        "}\n";

    GLuint shader = create_shader(vertsh, fragsh);

    glUseProgram(shader);
    glDeleteShader(shader);

    glClearColor(0.12f, 0.12f, 0.12f, 1.0f);

    while (!glfwWindowShouldClose(window))
    {
        /* render shit */

        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        /* process event bs */

        time_lasttime = time_gettime();
        glfwPollEvents();
    }

    glfwTerminate();
}