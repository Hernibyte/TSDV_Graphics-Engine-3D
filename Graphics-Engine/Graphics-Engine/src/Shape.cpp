#include "Shape.h"

Shape::Shape(Renderer& renderer) : Entity2D(renderer) {
	render->GenerateBuffers(vao, vbo, ebo);
	render->BindBuffers(vao, vbo, ebo);
	render->VertexAttributes();
	render->SetBufferData(vertex, vertexAmount, index, indexAmount);
}

void Shape::ChangeColor(float r, float g, float b) {
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

void Shape::ChangeAlpha(float alpha) {
	vertex[6] = alpha;
	vertex[15] = alpha;
	vertex[24] = alpha;
	vertex[33] = alpha;
}

void Shape::Rotate(float x, float y, float z) {
	transform.Rotate(x, y, z);
}

void Shape::SetPosition(float x, float y, float z) {
	transform.SetPosition(x, y, z);
}

void Shape::Translate(float x, float y, float z) {
	transform.Translate(x, y, z);
}

void Shape::Scale(float x, float y, float z) {
	transform.Scale(x, y, z);
}

void Shape::Draw() {
	render->Draw(vao, indexAmount, transform.Model());
}