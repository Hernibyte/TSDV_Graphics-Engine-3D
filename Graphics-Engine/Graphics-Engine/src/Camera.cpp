#include "Camera.h"

Camera::Camera(Renderer& renderer) {
	render = &renderer;
}

void Camera::SetPosition(float x, float y, float z) {
	render->internalCamera.cameraPos.x = x;
	render->internalCamera.cameraPos.y = y;
	render->internalCamera.cameraPos.z = z;
}

void Camera::Translate(float x, float y, float z) {
	render->internalCamera.cameraPos.x += x;
	render->internalCamera.cameraPos.y += y;
	render->internalCamera.cameraPos.z += z;
}

void Camera::Rotate(float x, float y, bool constrainPitch) {
	render->internalCamera.yaw += x;
	render->internalCamera.pitch += y;

	if (constrainPitch) {
		if (render->internalCamera.pitch > 89.0f)
			render->internalCamera.pitch = 89.0f;
		if (render->internalCamera.pitch < -89.0f)
			render->internalCamera.pitch = -89.0f;
	}

	UpdateCameraVectors();
}

void Camera::UpdateCameraVectors() {
	glm::vec3 front { };
	front.x = cos(glm::radians(render->internalCamera.yaw)) * cos(glm::radians(render->internalCamera.pitch));
	front.y = sin(glm::radians(render->internalCamera.pitch));
	front.z = sin(glm::radians(render->internalCamera.yaw)) * cos(glm::radians(render->internalCamera.pitch));
	render->internalCamera.cameraFront = glm::normalize(front);
	render->internalCamera.cameraRight = glm::normalize(glm::cross(render->internalCamera.cameraFront, render->internalCamera.worldUp));
	render->internalCamera.cameraUp = glm::normalize(glm::cross(render->internalCamera.cameraRight, render->internalCamera.cameraFront));
}

void Camera::SetProjection(ProjectionType type) {
	render->projectionType = type;
}

void Camera::TargetFirstPerson(Entity entity) {
	SetPosition(
		entity.transform.myposition.x,
		entity.transform.myposition.y,
		entity.transform.myposition.z
	);
}

void Camera::TargetThirdPerson(Entity entity, float y_offset, float z_offset) {
	SetPosition(
		entity.transform.myposition.x,
		entity.transform.myposition.y + y_offset,
		entity.transform.myposition.z + z_offset
	);
}