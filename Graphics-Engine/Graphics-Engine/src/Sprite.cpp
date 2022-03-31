#include "Sprite.h"

Sprite::Sprite(Renderer& renderer) : Entity2D(renderer) {
	render->GenerateBuffers(vao, vbo, ebo);
	render->BindBuffers(vao, vbo, ebo);
	render->VertexAttributes();
	render->SetBufferData(vertex, vertexAmount, index, indexAmount);
}

Sprite::Sprite(Renderer& renderer, const char* filePath, TextureType type)
	: Entity2D(renderer) {
	render->GenerateBuffers(vao, vbo, ebo);
	render->BindBuffers(vao, vbo, ebo);
	render->VertexAttributes();
	render->SetBufferData(vertex, vertexAmount, index, indexAmount);
	ImportTexture(filePath, type);
}

void Sprite::ImportTexture(const char* filePath, TextureType type) {
	//texture = TextureImporter::Import(filePath, type, texture);
	Renderer::GenerateTexture(texture);
}

void Sprite::ChangeColor(float r, float g, float b) {
	vertex[3] = r;
	vertex[15] = r;
	vertex[27] = r;
	vertex[39] = r;

	vertex[4] = g;
	vertex[16] = g;
	vertex[28] = g;
	vertex[40] = g;

	vertex[5] = b;
	vertex[17] = b;
	vertex[29] = b;
	vertex[41] = b;

	render->BindBuffers(vao, vbo, ebo);
	render->SetBufferData(vertex, vertexAmount, index, indexAmount);
}

void Sprite::ChangeAlpha(float alpha) {
	vertex[6] = alpha;
	vertex[18] = alpha;
	vertex[30] = alpha;
	vertex[42] = alpha;

	render->BindBuffers(vao, vbo, ebo);
	render->SetBufferData(vertex, vertexAmount, index, indexAmount);
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
	render->DrawTexture(vao, indexAmount, transform.Model(), texture, material);
}