#include "Mesh.h"

Mesh::Mesh(std::vector<Vertex> vertices, 
	std::vector<unsigned int> indices, 
	std::vector<Texture> textures, 
	Renderer& renderer) : Entity(renderer) {

	this->vertices = vertices;
	this->indices = indices;
	this->textures = textures;
	
	render->SetupMesh(vao, vbo, ebo, vertices, indices);
}

void Mesh::Draw(glm::mat4 parentModel) {
	render->DrawMesh(vao, indices.size(), parentModel, lightingMap, textures);
}