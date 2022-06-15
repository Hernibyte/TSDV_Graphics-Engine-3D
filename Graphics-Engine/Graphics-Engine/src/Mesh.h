#ifndef MESH_H
#define MESH_H

#include "Entity.h"
#include "Export.h"
#include "TextureImporter.h"
#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"

#include <string>
#include <vector>

class ENGINE_API Mesh : public Entity {
public:
	Mesh(std::vector<Vertex> vertices,
		std::vector<unsigned int> indices, 
		std::vector<Texture> textures, 
		Renderer& renderer);

	void Draw(glm::mat4 parentModel);

	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<Texture> textures;

	unsigned int vao;
private:
	unsigned int ebo, vbo;

	LightingMap lightingMap{};
};

#endif // !MESH_H
