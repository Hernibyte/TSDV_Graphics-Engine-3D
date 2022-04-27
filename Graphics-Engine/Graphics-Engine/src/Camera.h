#ifndef CAMERA_H
#define CAMERA_H

#include "Entity.h"

class Camera {
public:
	Camera() = delete;
	Camera(Renderer& renderer);

	void SetPosition(float x, float y, float z);

	void Translate(float x, float y, float z);

	void Rotate(float x, float y, bool constrainPitch = true);

	void SetProjection(ProjectionType type);

	void TargetFirstPerson(Entity entity);

	void TargetThirdPerson(Entity entity, float y_offset, float z_offset);
private:
	void UpdateCameraVectors();

	Renderer* render;
};

#endif // !CAMERA_H
