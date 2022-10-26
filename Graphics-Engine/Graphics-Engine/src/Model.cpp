#include "Model.h"

Model::Model(std::string const& path, Renderer& renderer, bool gamma) : Entity(renderer), gammaCorrection(gamma) {
	modelImporter.LoadModel(path);
}

void Model::Draw() {
	for (unsigned int i = 0; i < modelImporter.meshes.size(); i++) {
		modelImporter.meshes[i].Draw(transform.Model());
	}
}
