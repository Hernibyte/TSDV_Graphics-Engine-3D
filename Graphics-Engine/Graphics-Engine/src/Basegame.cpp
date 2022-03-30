#include "Basegame.h"

Basegame::Basegame() {
	window.Width(800);
	window.Height(800);
	window.Tittle("Window");
}

Basegame::Basegame(int width, int height, const char* tittle) {
	window.Width(width);
	window.Height(height);
	window.Tittle(tittle);
}

void Basegame::Run() {
	Core_Start();
	Start();

	while (!window.IsWindowShouldClose()) {
		time.Start();

		window.Clear(0, 0, 0, 0);

		Core_Update();
		Update();

		window.Refresh();

		time.Tick();
	}

	Core_Sleep();
}

void Basegame::Core_Start() {
	ShaderSource shaderSource = Renderer::ParceShader("src/StandardShader/StandardShader.glsl");
	render.CreateProgram(shaderSource.Vertex, shaderSource.Fragment);
	render.GenerateBuffers();
	render.BindBuffers();
	render.VertexAttributes();
	render.GetUniformsLocation();
}

void Basegame::Core_Update() {
	render.UpdateCamera();
}

void Basegame::Core_Sleep() {

}
