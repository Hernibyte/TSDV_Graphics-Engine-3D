#include "Shape.h"

Shape::Shape(Renderer& renderer) : Entity2D(renderer) {
	render->GenerateBuffers(vao, vbo, ebo);
	render->BindBuffers(vao, vbo, ebo);
	render->VertexAttributes();
	render->SetBufferData(vertex, vertexAmount, index, indexAmount);
}

Shape::Shape(Renderer& renderer, float r, float g, float b) : Entity2D(renderer) {
	render->GenerateBuffers(vao, vbo, ebo);
	render->BindBuffers(vao, vbo, ebo);
	render->VertexAttributes();
	render->SetBufferData(vertex, vertexAmount, index, indexAmount);
	ChangeColor(r, g, b);
}

void Shape::ChangeColor(float r, float g, float b) {
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

void Shape::ChangeAlpha(float alpha) {
	vertex[6] = alpha;
	vertex[18] = alpha;
	vertex[30] = alpha;
	vertex[42] = alpha;

	render->BindBuffers(vao, vbo, ebo);
	render->SetBufferData(vertex, vertexAmount, index, indexAmount);
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
	render->Draw(vao, indexAmount, transform.Model(), material);
}