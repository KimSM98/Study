//OpenGL 창 띄우기

#include "pch.h"
#include <iostream>
#include <gl/glew.h>
#include <GLFW/glfw3.h>
#pragma comment (lib, "glew32")
#include <glm/glm.hpp>

void render(GLFWwindow* window);
int main(void) {
	glm::vec3 a(1, 1, 0);
	if (!glfwInit())        exit(EXIT_FAILURE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif
	GLFWwindow* window = glfwCreateWindow(640, 480, "Hello", NULL, NULL);
	glfwMakeContextCurrent(window);
	glewInit();
	while (!glfwWindowShouldClose(window)) {
		render(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
}
void render(GLFWwindow* window) {
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	glClearColor(0, 0, .5, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);
}
