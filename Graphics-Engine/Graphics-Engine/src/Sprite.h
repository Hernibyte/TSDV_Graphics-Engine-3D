#ifndef SPRITE_H
#define SPRITE_H

#include "Shape.h"

class Sprite : public Entity2D {
public:
	Sprite(Renderer& renderer);

	Sprite(Renderer& renderer, const char* filePath, TextureType type);

	void ImportTexture(const char* filePath, TextureType type);

	void ChangeColor(float r, float g, float b);

	void ChangeAlpha(float alpha);

	void Rotate(float x, float y, float z);

	void SetPosition(float x, float y, float z);

	void Translate(float x, float y, float z);

	void Scale(float x, float y, float z);

	void Draw();

private:
	Material material{};

	unsigned int vao;
	unsigned int vbo;
	unsigned int ebo;

	unsigned int vertexAmount = 48;
	unsigned int indexAmount = 6;

	float vertex[48] = {
		 0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f, -1.0f,   1.0f, 1.0f,
		 0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f, -1.0f,   1.0f, 0.0f,
		-0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f, -1.0f,   0.0f, 0.0f,
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f, -1.0f,   0.0f, 1.0f
	};
	unsigned int index[6] = {
		0, 1, 3,
		1, 2, 3
	};
	Texture texture{};
};

#endif // !SPRITE_H
