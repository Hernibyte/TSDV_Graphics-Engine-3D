#include "ShapeCube.h"

ShapeCube::ShapeCube(Renderer& renderer) : Entity(renderer) {
	render->GenerateBuffers(vao, vbo, ebo);
	render->BindBuffers(vao, vbo, ebo);
	render->VertexAttributes();
	render->SetBufferData(vertex, vertexAmount, index, indexAmount);
}

void ShapeCube::Rotate(float x, float y, float z) {
	transform.Rotate(x, y, z);
}

void ShapeCube::SetPosition(float x, float y, float z) {
	transform.SetPosition(x, y, z);
}

void ShapeCube::Translate(float x, float y, float z) {
	transform.Translate(x, y, z);
}

void ShapeCube::Scale(float x, float y, float z) {
	transform.Scale(x, y, z);
}

void ShapeCube::Draw() {
	render->Draw(vao, indexAmount, transform.Model());
}