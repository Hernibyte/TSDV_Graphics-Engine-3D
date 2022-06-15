#ifndef MODEL_H
#define MODEL_H

#include "Export.h"
#include "Mesh.h"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

#include <map>

class ENGINE_API Model : public Entity {
public:
	std::vector<Texture> textures_loaded;
	std::vector<Mesh> meshes;
	std::string directory;
	bool gammaCorrection;

	Model(std::string const &path, Renderer& renderer, bool gamma = false);

	void Draw();

private:
	void LoadModel(std::string const &path);

	void ProcessNode(aiNode *node, const aiScene *scene);

	Mesh ProcessMesh(aiMesh *mesh, const aiScene *scene);

	std::vector<Texture> LoadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
};

#endif // !MODEL_H
