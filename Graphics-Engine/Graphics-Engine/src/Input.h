#ifndef INPUT_H
#define INPUT_H

#include "Window.h"

class Input {
public:
	Input(Window& window);
	bool GetKey(int keyCode);
	bool GetKeyMouse(int keyCode);
	void GetCursorPosition(double& x_position, double& y_position);
private:
	Window* _window;
};

#endif // !INPUT_H
