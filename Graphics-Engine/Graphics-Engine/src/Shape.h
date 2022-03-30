#ifndef SHAPE_H
#define SHAPE_H

#include "Entity2D.h"

class Shape : public Entity2D {
public:
	Shape(Renderer& renderer);

	Shape(Renderer& renderer, float r, float g, float b);

	void ChangeColor(float r, float g, float b);

	void ChangeAlpha(float alpha);

	void Rotate(float x, float y, float z);

	void SetPosition(float x, float y, float z);

	void Translate(float x, float y, float z);

	void Scale(float x, float y, float z);

	void Draw();

private:
	unsigned int vao;
	unsigned int vbo;
	unsigned int ebo;

	unsigned int vertexAmount = 36;
	unsigned int indexAmount = 6;

	float vertex[36] = {
		 0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
		 0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
		-0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f
	};
	unsigned int index[6] = {
		0, 1, 3,
		1, 2, 3
	};
};

#endif // !SHAPE_H
