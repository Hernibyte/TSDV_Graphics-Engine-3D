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

	spriteCube1.SetPosition(5, 0, 0);
	//nose.transform.Scale(100, 100, 100);

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

	seta.transform.SetParent(playerShape.transform.Model());

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

	if (input.GetKey(GLFW_KEY_UP))
		spotLightShape.Translate(0, 0.1f, 0);
	if (input.GetKey(GLFW_KEY_DOWN))
		spotLightShape.Translate(0, -0.1f, 0);
	if (input.GetKey(GLFW_KEY_RIGHT))
		spotLightShape.Translate(0.1f, 0, 0);
	if (input.GetKey(GLFW_KEY_LEFT))
		spotLightShape.Translate(-0.1f, 0, 0);

	if (input.GetKey(GLFW_KEY_I))
		seta.transform.Translate(0, 0.03f, 0);
	if (input.GetKey(GLFW_KEY_K))
		seta.transform.Translate(0, -0.03f, 0);
	if (input.GetKey(GLFW_KEY_J))
		seta.transform.Translate(-0.03f, 0, 0);
	if (input.GetKey(GLFW_KEY_L))
		seta.transform.Translate(0.03f, 0, 0);
	if (input.GetKey(GLFW_KEY_O))
		seta.transform.Translate(0, 0, -0.3f);
	if (input.GetKey(GLFW_KEY_U))
		seta.transform.Translate(0, 0, 0.3f);

	if (input.GetKey(GLFW_KEY_Y))
		setaScale += 0.02f;
	if (input.GetKey(GLFW_KEY_R))
		setaScale -= 0.02f;

	if (input.GetKey(GLFW_KEY_T))
		setaXRotation += 0.05f;
	if (input.GetKey(GLFW_KEY_G))
		setaXRotation -= 0.05f;
	if (input.GetKey(GLFW_KEY_H))
		setaYRotation += 0.05f;
	if (input.GetKey(GLFW_KEY_F))
		setaYRotation -= 0.05f;
	
	seta.transform.Scale(setaScale, setaScale, setaScale);
	seta.transform.Rotate(setaXRotation, setaYRotation, 0);

	spriteCube1.Draw();

	//nose.Draw();
	seta.Draw();

	if (input.GetKey(GLFW_KEY_C))
		spotLight.IsSet(1);
	else
		spotLight.IsSet(0);

	if (input.GetKey(GLFW_KEY_X))
		dirLight.IsSet(0);
	else
		dirLight.IsSet(1);

	spotLightShape.Draw();
	playerShape.Draw();
	pointLightShape1.Draw();
	pointLightShape2.Draw();
	pointLightShape3.Draw();
	pointLightShape4.Draw();
}
