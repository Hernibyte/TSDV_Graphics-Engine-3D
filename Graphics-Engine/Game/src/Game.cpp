#include "Game.h"

Game::Game(int width, int height, const char* tittle) : Basegame(width, height, tittle) { }

void Game::Start() {
	spriteCube1.ImportDiffuse("res/StoneWallDiffuse.png", TextureType::RGBA);
	spriteCube1.ImportSpecular("res/StineWallSpecular.png", TextureType::RGBA);

	spotLightShape.Scale(0.1f, 0.1f, 0.1f);
	playerShape.Scale(0.3f, 0.3f, 0.3f);

	spotLightShape.SetPosition(
		1,
		-0.2f,
		3.8f
	);

	pointLightShape1.SetPosition(0.7f, 0.2f, 2.0f);
	pointLightShape2.SetPosition(2.3f, -3.3f, -4.0f);
	pointLightShape3.SetPosition(-4.0f, 2.0f, -12.0f);
	pointLightShape4.SetPosition(0.0f, 0.0f, -3.0f);

	pointLightShape1.Scale(0.2f, 0.2f, 0.2f);
	pointLightShape2.Scale(0.2f, 0.2f, 0.2f);
	pointLightShape3.Scale(0.2f, 0.2f, 0.2f);
	pointLightShape4.Scale(0.2f, 0.2f, 0.2f);

	dirLight.Load();
	pointLight1.Load();
	pointLight2.Load();
	pointLight3.Load();
	pointLight4.Load();
	spotLight.Load();
}

void Game::Update() {
	camera.TargetThirdPerson(playerShape, 0.8f, 6.f);

	spotLight.SetPosition (
		spotLightShape.transform.myposition.x,
		spotLightShape.transform.myposition.y,
		spotLightShape.transform.myposition.z
	);

	if (input.GetKey(GLFW_KEY_W))
		playerShape.Translate(0, 0.1f, 0);
	if (input.GetKey(GLFW_KEY_S))
		playerShape.Translate(0, -0.1f, 0);
	if (input.GetKey(GLFW_KEY_D))
		playerShape.Translate(0.1f, 0, 0);
	if (input.GetKey(GLFW_KEY_A))
		playerShape.Translate(-0.1f, 0, 0);
	if (input.GetKey(GLFW_KEY_E))
		playerShape.Translate(0, 0, -0.1f);
	if (input.GetKey(GLFW_KEY_Q))
		playerShape.Translate(0, 0, 0.1f);

	if (input.GetKey(GLFW_KEY_I))
		spotLightShape.Translate(0, 0.1f, 0);
	if (input.GetKey(GLFW_KEY_K))
		spotLightShape.Translate(0, -0.1f, 0);
	if (input.GetKey(GLFW_KEY_L))
		spotLightShape.Translate(0.1f, 0, 0);
	if (input.GetKey(GLFW_KEY_J))
		spotLightShape.Translate(-0.1f, 0, 0);
	if (input.GetKey(GLFW_KEY_O))
		spotLightShape.Translate(0, 0, -0.1f);
	if (input.GetKey(GLFW_KEY_U))
		spotLightShape.Translate(0, 0, 0.1f);

	spriteCube1.Draw();
	spotLightShape.Draw();
	playerShape.Draw();
	pointLightShape1.Draw();
	pointLightShape2.Draw();
	pointLightShape3.Draw();
	pointLightShape4.Draw();
}
