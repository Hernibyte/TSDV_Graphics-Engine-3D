#ifndef SHAPECUBE_H
#define SHAPECUBE_H

#include "Entity.h"

class ShapeCube : public Entity {
public:
	ShapeCube(Renderer& renderer);

	void Rotate(float x, float y, float z);

	void SetPosition(float x, float y, float z);

	void Translate(float x, float y, float z);

	void Scale(float x, float y, float z);

	void Draw();
private:
	unsigned int vao;
	unsigned int vbo;
	unsigned int ebo;

	const int vertexAmount = 216;
	const int indexAmount = 36;

	float vertex[288] = {
		 0.5f,  0.5f, 0.5f,   1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
		 0.5f, -0.5f, 0.5f,   1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
		-0.5f, -0.5f, 0.5f,   1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
		-0.5f,  0.5f, 0.5f,   1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f,

		 0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f,

		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f,

		-0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f,

		-0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f
	};

	unsigned int index[36] = {
		0, 1, 3,
		1, 2, 3,
		4, 5, 7,
		5, 6, 7,
		8, 9, 11,
		9, 10, 11,
		12, 13, 15,
		13, 14, 15,
		16, 17, 19,
		17, 18, 19,
		20, 21, 23,
		21, 22, 23
	};
};

#endif // !SHAPECUBE_H
