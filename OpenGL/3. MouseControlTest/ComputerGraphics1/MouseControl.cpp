//Change Camera Position and fov for Mouse Control
//Somin Kim

#include "pch.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#pragma comment (lib, "glew32")
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>
#include "toys.h"
#include "j3a.hpp"
using namespace glm;
using namespace std;

int buttonPressed = false;
double lastX, lastY;
float theta = 0, phi = 0, fov = 60;
vec3 cameraPos = vec3(0, 0, 5);

void render(GLFWwindow* window);
void init();

void cursorPosCB(GLFWwindow* window, double x, double y) {
	if (buttonPressed) {
		int width, height;
		glfwGetWindowSize(window, &width, &height);
		float dx = (x - lastX) / width;
		float dy = (y - lastY) / height;

		theta += -dx * 3.141592f;
		phi += -dy * 3.141592f;
		cameraPos = vec3(rotate(phi, vec3(1, 0, 0)) * rotate(theta, vec3(0, 1, 0)) * vec4(0, 0, 5, 1));

		lastX = x;
		lastY = y;

	}
}

void mouseButtonCB(GLFWwindow* window, int button, int state, int mods) {
	if (button == GLFW_MOUSE_BUTTON_2) {//Mouse Right Button
		if (state == GLFW_PRESS) {
			buttonPressed = true;
			glfwGetCursorPos(window, &lastX, &lastY);
		}
		else
			buttonPressed = false;
	}
}

void scrollCB(GLFWwindow*, double, double y) {
	fov += y * 10;
	if (fov > 170)
		fov = 170;
	if (fov < 10)
		fov = 10;
}

int main(void) {
	vec3 a(1, 1, 0);
	if (!glfwInit())		exit(EXIT_FAILURE);

	GLFWwindow* window = glfwCreateWindow(640, 480, "Mouse Control", NULL, NULL);
	glfwSetCursorPosCallback(window, cursorPosCB);
	glfwSetMouseButtonCallback(window, mouseButtonCB);
	glfwSetScrollCallback(window, scrollCB);
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
GLuint elementArray = 0;

Program prog;

void init() {
	prog.loadShaders("shader.vert", "shader.frag");
	loadJ3A("bunny.j3a");
		
	glGenVertexArrays(1, &vertexArray);

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, nVertices[0] * sizeof(vec3), vertices[0], GL_STATIC_DRAW);
	
	glBindVertexArray(vertexArray);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, nullptr);

	glGenBuffers(1, &elementArray);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementArray);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, nTriangles[0] * sizeof(glm::u32vec3), triangles[0], GL_STATIC_DRAW);

}



void render(GLFWwindow* window) {
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(prog.programID);
	
	mat4 objMat = rotate(90 * 3.14159265358979f / 180, vec3(1, 0, 0));
	
	GLuint loc = glGetUniformLocation(prog.programID, "objMat");
	glUniformMatrix4fv(loc, 1, false, value_ptr(objMat));
	
	mat4 viewMat = lookAt(cameraPos, vec3(0), vec3(0, 1, 0));
	loc = glGetUniformLocation(prog.programID, "viewMat");
	glUniformMatrix4fv(loc, 1, false, value_ptr(viewMat));

	mat4 projMat = perspective(fov*3.141592f / 180, width / (float)height, 0.1f, 100.f);
	loc = glGetUniformLocation(prog.programID, "projMat");
	glUniformMatrix4fv(loc, 1, false, value_ptr(projMat));

	glBindVertexArray(vertexArray);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementArray);

	glDrawElements(GL_TRIANGLES, nTriangles[0] * 3, GL_UNSIGNED_INT, 0);

	glfwSwapBuffers(window);
}