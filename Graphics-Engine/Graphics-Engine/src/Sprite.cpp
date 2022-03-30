#include "Sprite.h"

Sprite::Sprite(Renderer& renderer) : Entity2D(renderer) {

}

void Sprite::ImportTexture(const char* filePath, TextureType type) {
	texture = TextureImporter::Import(filePath, type, texture);
	Renderer::GenerateTexture(texture);
}

void Sprite::ChangeColor(float r, float g, float b) {
	vertex[3] = r;
	vertex[12] = r;
	vertex[21] = r;
	vertex[30] = r;

	vertex[4] = g;
	vertex[13] = g;
	vertex[22] = g;
	vertex[31] = g;

	vertex[5] = b;
	vertex[14] = b;
	vertex[23] = b;
	vertex[32] = b;
}

void Sprite::ChangeAlpha(float alpha) {
	vertex[6] = alpha;
	vertex[15] = alpha;
	vertex[24] = alpha;
	vertex[33] = alpha;
}

void Sprite::Rotate(float x, float y, float z) {
	transform.Rotate(x, y, z);
}

void Sprite::SetPosition(float x, float y, float z) {
	transform.SetPosition(x, y, z);
}

void Sprite::Translate(float x, float y, float z) {
	transform.Translate(x, y, z);
}

void Sprite::Scale(float x, float y, float z) {
	transform.Scale(x, y, z);
}

void Sprite::Draw() {
	render->Draw(vertex, index, transform.Model(), texture);
}