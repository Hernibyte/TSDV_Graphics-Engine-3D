#ifndef LIGHT_H
#define LIGHT_H

#include "Renderer.h"
#include "Export.h"

class ENGINE_API Light {
public:
	Light(Renderer& renderer);

	void Translate(float x, float y, float z);

	void SetPosition(float x, float y, float z);

	void Load();
private:
	LightData data{ glm::vec3(1.0f), 1, 1, 1};
	Renderer* render;
};

#endif // !LIGHT_H
