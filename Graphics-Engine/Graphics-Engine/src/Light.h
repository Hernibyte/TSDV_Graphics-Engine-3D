#ifndef LIGHT_H
#define LIGHT_H

#include "Renderer.h"

class Light {
public:
	Light(Renderer& renderer);

	void Translate(float x, float y, float z);

	void SetPosition(float x, float y, float z);

	void Draw();
private:
	LightData data{ glm::vec3(1.0f), 1, 1, 1};
	Renderer* render;
};

#endif // !LIGHT_H
