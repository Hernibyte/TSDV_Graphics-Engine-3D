#ifndef MODELIMPORTER_H
#define MODELIMPORTER_H

#include "Export.h"
#include "Mesh.h"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"
#include <map>

class ENGINE_API ModelImporter {
public:
	ModelImporter(Renderer* render);

	void LoadModel(std::string const& path);

	void ProcessNode(aiNode* node, const aiScene* scene);

	Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);

	std::vector<Texture> LoadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);

	std::vector<Texture> textures_loaded;
	std::vector<Mesh> meshes;
	std::string directory;
	Renderer* render;
};

#endif // MODELIMPORTER_H
