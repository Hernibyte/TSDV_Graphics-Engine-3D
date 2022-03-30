#include "Input.h"

Input::Input(Window& window) {
	_window = &window;
}

bool Input::GetKey(int keyCode) {
	return glfwGetKey(_window->glfwWindow(), keyCode) == GLFW_PRESS;
}

bool Input::GetKeyMouse(int keyCode) {
	return glfwGetMouseButton(_window->glfwWindow(), keyCode) == GLFW_PRESS;
}