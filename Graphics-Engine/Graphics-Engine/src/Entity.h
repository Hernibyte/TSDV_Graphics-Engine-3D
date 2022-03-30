#ifndef ENTITY_H
#define ENTITY_H

#include "Renderer.h"

class Entity {
public:
	Transform transform;
	
	Entity(Renderer& renderer) {
		render = &renderer;
		transform = Transform();
	}

protected:
	Renderer* render;
};

#endif // !ENTITY_H
