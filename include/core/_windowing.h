#include <GLFW/glfw3.h>

#ifndef CORE_WINDOWING_H
#define CORE_WINDOWING_H

GLFWwindow* window;

typedef struct {
	uint16_t width;
	uint16_t height;
	const char* title;
} GameWindow;

int window_init();
int window_createwindow(GameWindow* gamewindow);

#endif
