//Texture Mapping & Bump Mapping_Somin Kim

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
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
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
	if (button == GLFW_MOUSE_BUTTON_2) {
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

	GLFWwindow* window = glfwCreateWindow(640, 480, "Texture Mapping", NULL, NULL);
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
GLuint normalBuffer = 0;
GLuint texCoordBuffer = 0;
GLuint vertexArray = 0;
GLuint elementArray = 0;
GLuint textureID = 0;
GLuint bumpID = 0;

Program prog;

void init() {
	prog.loadShaders("shader.vert", "shader.frag");
	loadJ3A("dwarf.j3a");

	glGenVertexArrays(1, &vertexArray);

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, nVertices[0] * sizeof(vec3), vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, nVertices[0] * sizeof(vec3), normals[0], GL_STATIC_DRAW);

	glGenBuffers(1, &texCoordBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, texCoordBuffer);
	glBufferData(GL_ARRAY_BUFFER, nVertices[0] * sizeof(vec2), texCoords[0], GL_STATIC_DRAW);

	glBindVertexArray(vertexArray);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, nullptr);

	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, false, 0, nullptr);

	glBindBuffer(GL_ARRAY_BUFFER, texCoordBuffer);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, false, 0, nullptr);

	glGenBuffers(1, &elementArray);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementArray);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, nTriangles[0] * sizeof(glm::u32vec3), triangles[0], GL_STATIC_DRAW);


	int w = 0, h = 0, n = 0;
	void* buf = stbi_load("dwarfD.jpg", &w, &h, &n, 4);
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_SRGB8_ALPHA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, buf);
	stbi_image_free(buf);

	buf = stbi_load("dwarfB.jpg", &w, &h, &n, 4);
	glGenTextures(1, &bumpID);
	glBindTexture(GL_TEXTURE_2D, bumpID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, buf);
	stbi_image_free(buf);

}



void render(GLFWwindow* window) {
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	glUseProgram(prog.programID);

	mat4 objMat = mat4(1);
	objMat = rotate(-theta, vec3(0, 1, 0)) * rotate(-phi, vec3(1, 0, 0));

	GLuint loc = glGetUniformLocation(prog.programID, "objMat");
	glUniformMatrix4fv(loc, 1, false, value_ptr(objMat));

	mat4 viewMat = lookAt(vec3(0, 0, 5), vec3(0), vec3(0, 1, 0));
	loc = glGetUniformLocation(prog.programID, "viewMat");
	glUniformMatrix4fv(loc, 1, false, value_ptr(viewMat));

	mat4 projMat = perspective(fov*3.141592f / 180, width / (float)height, 0.1f, 100.f);
	loc = glGetUniformLocation(prog.programID, "projMat");
	glUniformMatrix4fv(loc, 1, false, value_ptr(projMat));

	glBindVertexArray(vertexArray);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementArray);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureID);
	loc = glGetUniformLocation(prog.programID, "diffTex");
	glUniform1i(loc, 0);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, bumpID);
	loc = glGetUniformLocation(prog.programID, "bumpTex");
	glUniform1i(loc, 1);

	glDrawElements(GL_TRIANGLES, nTriangles[0] * 3, GL_UNSIGNED_INT, 0);

	glfwSwapBuffers(window);
}