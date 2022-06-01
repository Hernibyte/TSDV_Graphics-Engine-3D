#ifndef DIRECTIONALLIGHT_H
#define DIRECTIONALLIGHT_H

#include "Renderer.h"
#include "Export.h"

class ENGINE_API DirectionalLight {
public:
	DirectionalLight(Renderer& renderer);

	DirectionalLight(
		Renderer& renderer, 
		glm::vec3 direction, 
		glm::vec3 ambient, 
		glm::vec3 diffuse, 
		glm::vec3 specular
	);

	void SetDirection(float x, float y, float z);

	void SetAmbient(float x, float y, float z);

	void SetDiffuse(float x, float y, float z);

	void SetSpecular(float x, float y, float z);

	void Load();
private:
	DirectionalLightData data{};
	Renderer* render;
};

#endif // !DIRECTIONALLIGHT_H
