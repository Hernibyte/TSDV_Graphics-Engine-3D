#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(Renderer& renderer) {
	render = &renderer;
}

DirectionalLight::DirectionalLight(
	Renderer& renderer,
	glm::vec3 direction,
	glm::vec3 ambient,
	glm::vec3 diffuse,
	glm::vec3 specular 
) {
	render = &renderer;
	data.direction = direction;
	data.ambient = ambient;
	data.diffuse = diffuse;
	data.specular = specular;
}

void DirectionalLight::SetDirection(float x, float y, float z) {
	data.direction = glm::vec3{ x, y, z };
}

void DirectionalLight::SetAmbient(float x, float y, float z) {
	data.ambient = glm::vec3{ x, y, z };
}

void DirectionalLight::SetDiffuse(float x, float y, float z) {
	data.diffuse = glm::vec3{ x, y, z };
}

void DirectionalLight::SetSpecular(float x, float y, float z) {
	data.specular = glm::vec3{ x, y, z };
}

void DirectionalLight::Load() {
	render->SetDirectionalLight(data);
}