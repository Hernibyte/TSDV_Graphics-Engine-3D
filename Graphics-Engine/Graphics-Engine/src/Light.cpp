#include "Light.h"

Light::Light(Renderer& renderer) {
	render = &renderer;
}

void Light::Translate(float x, float y, float z) {
	data.position[0] += x;
	data.position[1] += y;
	data.position[2] += z;
}

void Light::SetPosition(float x, float y, float z) {
	data.position[0] = x;
	data.position[1] = y;
	data.position[2] = z;
}

void Light::Draw() {
	render->SetLight(data);
}