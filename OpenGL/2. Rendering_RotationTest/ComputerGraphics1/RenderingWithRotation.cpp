//Rendering with Rotation_Somin Kim

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


void render(GLFWwindow* window);
void init();
int i = 0;

int main(void) {
	if (!glfwInit())		exit(EXIT_FAILURE);

	GLFWwindow* window = glfwCreateWindow(640, 480, "Rendering with Rotation", NULL, NULL);
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
	objMat = rotate((1+i*0.25f) * 3.14159265358979f / 180, vec3(0, 1, 0)) * objMat;
	
	GLuint loc = glGetUniformLocation(prog.programID, "objMat");
	glUniformMatrix4fv(loc, 1, false, value_ptr(objMat));
	
	glBindVertexArray(vertexArray);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementArray);

	glDrawElements(GL_TRIANGLES, nTriangles[0] * 3, GL_UNSIGNED_INT, 0);

	glfwSwapBuffers(window);
	i++;
}