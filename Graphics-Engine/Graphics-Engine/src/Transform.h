#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "glm/glm/matrix.hpp"
#include "glm/glm/gtc/type_ptr.hpp"
#include "Export.h"

class ENGINE_API Transform {
public:
	Transform() {
		model = glm::mat4(1.0f);
		rotatex = glm::mat4(1.0f);
		rotatey = glm::mat4(1.0f);
		rotatez = glm::mat4(1.0f);
		scale = glm::mat4(1.0f);
		translate = glm::mat4(1.0f);

		myposition = glm::vec3();
		myrotation = glm::quat();
		mylocalScale = glm::vec3();
	}

	inline bool HasParent() {
		return hasParent;
	}

	inline glm::mat4 Model() {
		if (hasParent) return parentTransform->Model() * model;
		return model;
	}

	inline void SetParent(Transform* parent) {
		parentTransform = parent;
		hasParent = true;
	}

	inline void UnBindParent() {
		hasParent = false;
	}

	inline void Rotate(float x, float y, float z) {
		RotateX(x);
		RotateY(y);
		RotateZ(z);
	}
	inline void SetPosition(float x, float y, float z) {
		myposition[0] = x;
		myposition[1] = y;
		myposition[2] = z;

		translate = glm::translate(glm::mat4(1.0f), myposition);
		UpdateModel();
	}
	inline void Translate(float x, float y, float z) {
		myposition[0] += x;
		myposition[1] += y;
		myposition[2] += z;

		translate = glm::translate(glm::mat4(1.0f), myposition);
		UpdateModel();
	}
	inline void Scale(float x, float y, float z) {
		mylocalScale[0] = x;
		mylocalScale[1] = y;
		mylocalScale[2] = z;

		scale = glm::scale(glm::mat4(1.0f), mylocalScale);
		UpdateModel();
	}

	glm::vec3 myposition;
	glm::quat myrotation;
	glm::vec3 mylocalScale;
private:
	inline void RotateX(float x) {
		myrotation[0] = x;
		glm::vec3 axis = { 0.0f, 0.0f, 1.0f };
		axis[0] = 1.0f;
		axis[1] = 0.0f;
		axis[2] = 0.0f;

		rotatex = glm::rotate(glm::mat4(1.0f), x, axis);
		UpdateModel();
	}
	inline void RotateY(float y) {
		myrotation[1] = y;
		glm::vec3 axis = { 0.0f, 0.0f, 1.0f };
		axis[0] = 0.0f;
		axis[1] = 1.0f;
		axis[2] = 0.0f;

		rotatey = glm::rotate(glm::mat4(1.0f), y, axis);
		UpdateModel();
	}
	inline void RotateZ(float z) {
		myrotation[2] = z;
		glm::vec3 axis = { 0.0f, 0.0f, 1.0f };
		axis[0] = 0.0f;
		axis[1] = 0.0f;
		axis[2] = 1.0f;

		rotatez = glm::rotate(glm::mat4(1.0f), z, axis);
		UpdateModel();
	}

	void UpdateModel() {
		model = translate * rotatex * rotatey * rotatez * scale;
	}

	glm::mat4 model;

	bool hasParent = false;
	Transform* parentTransform;

	glm::mat4 translate;
	glm::mat4 rotatex;
	glm::mat4 rotatey;
	glm::mat4 rotatez;
	glm::mat4 scale;
};

#endif // !TRRANSFORM_H
