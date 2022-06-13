#ifndef MESH_H
#define MESH_H

#include "Entity.h"
#include "Export.h"
#include "TextureImporter.h"
#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"

#include <string>
#include <vector>

#define MAX_BONE_INFLUENCE 4

struct ENGINE_API Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoord;
	glm::vec3 tangent;
	glm::vec3 bitangent;
	
	int m_BoneIDs[MAX_BONE_INFLUENCE];
	float m_Weights[MAX_BONE_INFLUENCE];
};

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
