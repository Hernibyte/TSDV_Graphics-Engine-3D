#ifndef SPOTLIGHT_H
#define SPOTLIGHT_H

#include "Renderer.h"
#include "Export.h"

class ENGINE_API SpotLight {
public:
	SpotLight(Renderer& renderer);

	SpotLight(
		Renderer& renderer,
		glm::vec3 position,
		glm::vec3 direction,
		float cutOff,
		float outerCutOff,
		float constant,
		float linear,
		float quadratic,
		glm::vec3 ambient,
		glm::vec3 diffuse,
		glm::vec3 specular
	);

	void IsSet(int value);

	void SetPosition(float x, float y, float z);

	void SetDirection(float x, float y, float z);

	void SetCutOff(float cutOff);

	void SetOuterCutOff(float outerCutOff);

	void SetConstant(float constant);

	void Setlinear(float linear);

	void SetQuadratic(float quadratic);

	void SetAmbient(float x, float y, float z);

	void SetDiffuse(float x, float y, float z);

	void SetSpecular(float x, float y, float z);

	void Load();
private:
	SpotLightData data{};
	Renderer* render;
};

#endif // !SPOTLIGHT_H
