#ifndef MODEL_H
#define MODEL_H

#include "ModelImporter.h"

class ENGINE_API Model : public Entity {
public:
	Model(std::string const &path, Renderer& renderer, bool gamma = false);

	void Draw();

	ModelImporter modelImporter = ModelImporter(render);
	bool gammaCorrection;
};

#endif // !MODEL_H
