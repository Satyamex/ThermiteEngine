#include <GLFW/glfw3.h>
#include <core/_time.h>

double time_lasttime = 0.0;

double time_gettime(void)
{
	return glfwGetTime();
}

double time_getdeltatime(void)
{
	double delta_time = time_gettime() - time_lasttime;
	return delta_time;
}