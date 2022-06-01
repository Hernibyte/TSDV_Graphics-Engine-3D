#include "Game.h"

Game::Game(int width, int height, const char* tittle) : Basegame(width, height, tittle) { }

void Game::Start() {
	spriteCube1.ImportDiffuse("res/StoneWallDiffuse.png", TextureType::RGBA);
	spriteCube1.ImportSpecular("res/StineWallSpecular.png", TextureType::RGBA);

	shapeCube1.Scale(0.1f, 0.1f, 0.1f);
	shapeCube2.Scale(0.3f, 0.3f, 0.3f);

	shapeCube1.SetPosition(
		1,
		-0.2f,
		3.8f
	);
}

void Game::Update() {
	camera.TargetThirdPerson(shapeCube2, 0.8f, 6.f);

	light1.SetPosition(
		shapeCube1.transform.myposition.x,
		shapeCube1.transform.myposition.y,
		shapeCube1.transform.myposition.z
	);

	if (input.GetKey(GLFW_KEY_W))
		shapeCube2.Translate(0, 0.2f, 0);
	if (input.GetKey(GLFW_KEY_S))
		shapeCube2.Translate(0, -0.2f, 0);
	if (input.GetKey(GLFW_KEY_D))
		shapeCube2.Translate(0.2f, 0, 0);
	if (input.GetKey(GLFW_KEY_A))
		shapeCube2.Translate(-0.2f, 0, 0);
	if (input.GetKey(GLFW_KEY_E))
		shapeCube2.Translate(0, 0, -0.2f);
	if (input.GetKey(GLFW_KEY_Q))
		shapeCube2.Translate(0, 0, 0.2f);

	if (input.GetKey(GLFW_KEY_I))
		shapeCube1.Translate(0, 0.2f, 0);
	if (input.GetKey(GLFW_KEY_K))
		shapeCube1.Translate(0, -0.2f, 0);
	if (input.GetKey(GLFW_KEY_L))
		shapeCube1.Translate(0.2f, 0, 0);
	if (input.GetKey(GLFW_KEY_J))
		shapeCube1.Translate(-0.2f, 0, 0);
	if (input.GetKey(GLFW_KEY_O))
		shapeCube1.Translate(0, 0, -0.2f);
	if (input.GetKey(GLFW_KEY_U))
		shapeCube1.Translate(0, 0, 0.2f);

	light1.Draw();
	spriteCube1.Draw();
	shapeCube1.Draw();
	shapeCube2.Draw();
}
