#include "SpriteCube.h"

SpriteCube::SpriteCube(Renderer& renderer) : Entity(renderer) {
	render->GenerateBuffers(vao, vbo, ebo);
	render->BindBuffers(vao, vbo, ebo);
	render->VertexAttributes();
	render->SetBufferData(vertex, vertexAmount, index, indexAmount);
}

void SpriteCube::ImportDiffuse(const char* filePath, TextureType type) {
	TextureImporter::Import(filePath, type, lightingMap.diffuse);
	Renderer::GenerateTexture(lightingMap.diffuse);
}

void SpriteCube::ImportSpecular(const char* filePath, TextureType type) {
	TextureImporter::Import(filePath, type, lightingMap.specular);
	Renderer::GenerateTexture(lightingMap.specular);
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
	render->DrawTexture(vao, indexAmount, transform.Model(), lightingMap);
}