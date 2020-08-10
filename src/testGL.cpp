#include "tests.h"

#include <iostream>
#include <gl/GL.h>

void testGL(uint32_t* major, uint32_t* minor)
{
	*major = 0;
	*minor = 0;

	if (!glfwInit())
		return;

	/*** CREATE A HIDDEN WINDOW TO MAKE A GL CONTEXT ***/
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	GLFWwindow* window = glfwCreateWindow(200, 200, "", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);

	/*** QUERY OPENGL VERSION ***/
	const GLubyte* versionString = glGetString(GL_VERSION);

	int i = 0;
	for (; versionString[i] >= '0' && versionString[i] <= '9'; i++)
	{
		*major *= 10;
		*major += versionString[i] - '0';
	}
	i++;
	for (; versionString[i] >= '0' && versionString[i] <= '9'; i++)
	{
		*minor *= 10;
		*minor += versionString[i] - '0';
	}

	glfwTerminate();
}