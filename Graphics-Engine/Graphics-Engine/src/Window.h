#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include "GLEW/include/GL/glew.h"
#include "GLFW/include/glfw3.h"

class Window {
public:
	Window();
	Window(int width, int height, const char* tittle);
	~Window();

	void Width(int width);
	int Width();

	void Height(int height);
	int Height();

	void Tittle(const char* tittle);
	const char* Tittle();

	void SetWindowShouldClose(bool state);
	bool IsWindowShouldClose();

	GLFWwindow* glfwWindow();

	void UpdateAttributes();

	void Refresh();

	void Clear(GLclampf r = 1, GLclampf g = 1, GLclampf b = 1, GLclampf a = 1);
private:
	void Start();

	int width;
	int height;
	const char* tittle;
	GLFWwindow* WinMain;
};

#endif // !WINDOWN_H
