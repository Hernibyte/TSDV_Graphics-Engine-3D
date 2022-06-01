#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "Renderer.h"
#include "Export.h"

class ENGINE_API PointLight {
public:
	PointLight(Renderer& renderer, int lightNumber);

	PointLight(
		Renderer& renderer,
		int lightNumber,
		glm::vec3 position,
		float constant,
		float linear,
		float quadratic,
		glm::vec3 ambient,
		glm::vec3 diffuse,
		glm::vec3 specular
	);

	void SetPosition(float x, float y, float z);

	void SetConstant(float constant);

	void SetLinear(float linear);

	void SetQuadratic(float quadratic);

	void SetAmbient(float x, float y, float z);

	void SetDiffuse(float x, float y, float z);

	void SetSpecular(float x, float y, float z);

	void Load();
private:
	PointLightData data{};
	Renderer* render;
	int _lightNumber;
};

#endif // !POINTLIGHT_H
