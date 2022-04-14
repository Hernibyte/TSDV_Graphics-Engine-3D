#include "SpriteCube.h"

SpriteCube::SpriteCube(Renderer& renderer) : Entity(renderer) {
	render->GenerateBuffers(vao, vbo, ebo);
	render->BindBuffers(vao, vbo, ebo);
	render->VertexAttributes();
	render->SetBufferData(vertex, vertexAmount, index, indexAmount);
}

SpriteCube::SpriteCube(Renderer& renderer, const char* filePath, TextureType type) : Entity(renderer) {
	render->GenerateBuffers(vao, vbo, ebo);
	render->BindBuffers(vao, vbo, ebo);
	render->VertexAttributes();
	render->SetBufferData(vertex, vertexAmount, index, indexAmount);
	ImportTexture(filePath, type);
}

void SpriteCube::ImportTexture(const char* filePath, TextureType type) {
	TextureImporter::Import(filePath, type, texture);
	Renderer::GenerateTexture(texture);
}

void SpriteCube::Rotate(float x, float y, float z) {
	transform.Rotate(x, y, z);
}

void SpriteCube::SetPosition(float x, float y, float z) {
	transform.SetPosition(x, y, z);
}

void SpriteCube::Translate(float x, float y, float z) {
	transform.Translate(x, y, z);
}

void SpriteCube::Scale(float x, float y, float z) {
	transform.Scale(x, y, z);
}

void SpriteCube::Draw() {
	render->DrawTexture(vao, indexAmount, transform.Model(), texture, material);
}