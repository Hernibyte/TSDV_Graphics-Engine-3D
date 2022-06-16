#include "PointLight.h"

PointLight::PointLight(Renderer& renderer, int lightNumber) {
	render = &renderer;
	_lightNumber = lightNumber;
}

PointLight::PointLight (
	Renderer& renderer,
	int lightNumber,
	glm::vec3 position,
	float constant,
	float linear,
	float quadratic,
	glm::vec3 ambient,
	glm::vec3 diffuse,
	glm::vec3 specular
) {
	render = &renderer;
	_lightNumber = lightNumber;

	data.position = position;
	data.constant = constant;
	data.linear = linear;
	data.quadratic = quadratic;
	data.ambient = ambient;
	data.diffuse = diffuse;
	data.specular = specular;
}

void PointLight::IsSet(int value) {
	data.lightIsSet = value;
}

void PointLight::SetPosition(float x, float y, float z) {
	data.position = glm::vec3{ x, y, z };
}

void PointLight::SetConstant(float constant) {
	data.constant = constant;
}

void PointLight::SetLinear(float linear) {
	data.linear = linear;
}

void PointLight::SetQuadratic(float quadratic) {
	data.quadratic = quadratic;
}

void PointLight::SetAmbient(float x, float y, float z) {
	data.ambient = glm::vec3{ x, y, z };
}

void PointLight::SetDiffuse(float x, float y, float z) {
	data.diffuse = glm::vec3{ x, y, z };
}

void PointLight::SetSpecular(float x, float y, float z) {
	data.specular = glm::vec3{ x, y, z };
}

void PointLight::Load() {
	render->AddPointLight(data, _lightNumber);
}
