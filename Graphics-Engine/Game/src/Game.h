#ifndef GAME_H
#define GAME_H

#include "Basegame.h"

class Game : public Basegame {
public:
	Game(int width, int height, const char* tittle);

	void Start();
	void Update();

private:
	Camera camera{ render };
	
	DirectionalLight dirLight {
		render,
		glm::vec3{ -0.2f, -1.0f, -0.3f },
		glm::vec3{ 0.05f, 0.05f, 0.05f },
		glm::vec3{ 0.4f, 0.4f, 0.4f },
		glm::vec3{ 0.5f, 0.5f, 0.5f }
	};
	PointLight pointLight1 { 
		render, 
		0,
		glm::vec3{0.7f,  0.2f,  2.0f},
		1.0f,
		0.09f,
		0.032f,
		glm::vec3{0.05f, 0.05f, 0.05f},
		glm::vec3{0.8f, 0.8f, 0.8f},
		glm::vec3{1.0f, 1.0f, 1.0f}
	};
	PointLight pointLight2 { 
		render, 
		1,
		glm::vec3{2.3f, -3.3f, -4.0f},
		1.0f,
		0.09f,
		0.032f,
		glm::vec3{0.05f, 0.05f, 0.05f},
		glm::vec3{0.8f, 0.8f, 0.8f},
		glm::vec3{1.0f, 1.0f, 1.0f}
	};
	PointLight pointLight3 { 
		render, 
		2,
		glm::vec3{-4.0f,  2.0f, -12.0f},
		1.0f,
		0.09f,
		0.032f,
		glm::vec3{0.05f, 0.05f, 0.05f},
		glm::vec3{0.8f, 0.8f, 0.8f},
		glm::vec3{1.0f, 1.0f, 1.0f}
	};
	PointLight pointLight4 { 
		render,
		3,
		glm::vec3{0.0f,  0.0f, -3.0f},
		1.0f,
		0.09f,
		0.032f,
		glm::vec3{0.05f, 0.05f, 0.05f},
		glm::vec3{0.8f, 0.8f, 0.8f},
		glm::vec3{1.0f, 1.0f, 1.0f}
	};
	SpotLight spotLight { 
		render,
		spotLightShape.transform.myposition,
		camera.Front(),
		glm::cos(glm::radians(12.5f)),
		glm::cos(glm::radians(15.0f)),
		1.0f,
		0.09f,
		0.032f,
		glm::vec3{0.0f, 0.0f, 0.0f},
		glm::vec3{1.0f, 1.0f, 1.0f},
		glm::vec3{1.0f, 1.0f, 1.0f}
	};

	SpriteCube spriteCube1{ render };

	ShapeCube playerShape{ render };

	ShapeCube spotLightShape{ render };
	ShapeCube pointLightShape1{ render };
	ShapeCube pointLightShape2{ render };
	ShapeCube pointLightShape3{ render };
	ShapeCube pointLightShape4{ render };

	Model seta{ "res/seta/mushroom.obj" , render};
};

#endif // !GAME_H
