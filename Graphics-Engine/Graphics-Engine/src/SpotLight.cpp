#include "SpotLight.h"

SpotLight::SpotLight(Renderer& renderer) {
	render = &renderer;
}

SpotLight::SpotLight(
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
) {
	render = &renderer;

	data.position = position;
	data.direction = direction;
	data.cutOff = cutOff;
	data.outerCutOff = outerCutOff;
	data.constant = constant;
	data.linear = linear;
	data.quadratic = quadratic;
	data.ambient = ambient;
	data.diffuse = diffuse;
	data.specular = specular;
}

void SpotLight::SetPosition(float x, float y, float z) {
	data.position = glm::vec3{ x, y, z };
}

void SpotLight::SetDirection(float x, float y, float z) {
	data.direction = glm::vec3{ x, y, z };
}

void SpotLight::SetCutOff(float cutOff) {
	data.cutOff = cutOff;
}

void SpotLight::SetOuterCutOff(float outerCutOff) {
	data.outerCutOff = outerCutOff;
}

void SpotLight::SetConstant(float constant) {
	data.constant = constant;
}

void SpotLight::Setlinear(float linear) {
	data.linear = linear;
}

void SpotLight::SetQuadratic(float quadratic) {
	data.quadratic = quadratic;
}

void SpotLight::SetAmbient(float x, float y, float z) {
	data.ambient = glm::vec3{ x, y, z };
}

void SpotLight::SetDiffuse(float x, float y, float z) {
	data.diffuse = glm::vec3{ x, y, z };
}

void SpotLight::SetSpecular(float x, float y, float z) {
	data.specular = glm::vec3{ x, y, z };
}

void SpotLight::Load() {
	render->SetSpotLight(data);
}