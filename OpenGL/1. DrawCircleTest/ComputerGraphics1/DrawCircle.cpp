// Draw Circle_Somin Kim 

#include "pch.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#pragma comment (lib, "glew32")
#include <glm/glm.hpp>
#include <vector>
#include "toys.h"
#include <math.h>
using namespace glm;
using namespace std;

void render(GLFWwindow* window);
void init();

int main(void) {
	if (!glfwInit())		exit(EXIT_FAILURE);

	GLFWwindow* window = glfwCreateWindow(640, 640, "Circle", NULL, NULL);
	glfwMakeContextCurrent(window);
	glewInit();
	init();

	while (!glfwWindowShouldClose(window)) {
		render(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
}

GLuint vertexBuffer = 0;
GLuint vertexArray = 0;
vector<vec3> vertices;

Program prog;

void init() {
	prog.loadShaders("shader.vert", "shader.frag");

	vertices.push_back(vec3(0, 0, 0));

	int N = 72; //number of vertex
	for (int i = 0; i <= 360; i++) {
		double theta = i * 3.141592 / 180;
		double x = cos(theta);
		double y = sin(theta);
		if(i%(360/N)==0)
			vertices.push_back(vec3(x, y, 0));		
	}

	glGenVertexArrays(1, &vertexArray);

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vec3), vertices.data(), GL_STATIC_DRAW);

	glBindVertexArray(vertexArray);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, nullptr);

}

void render(GLFWwindow* window) {
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(prog.programID);
	glBindVertexArray(vertexArray);
	glDrawArrays(GL_TRIANGLE_FAN, 0, vertices.size());

	glfwSwapBuffers(window);
}