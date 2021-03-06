#ifndef ENTITY2D_H
#define ENTITY2D_H

#include "Entity.h"
#include "Export.h"

class ENGINE_API Entity2D : public Entity {
public:
	Entity2D(Renderer& renderer) : Entity(renderer) { }
};

#endif // !ENTITY_H
