#ifndef RENDERER_H
#define RENDERER_H

#include "Input.h"
#include "ShaderSource.h"
#include "Transform.h"
#include "TextureImporter.h"
#include <fstream>
#include <sstream>

struct InternalCamera {
	glm::mat4 view;
	glm::mat4 projection;
	glm::vec3 cameraPos { 0, 0, 3.0f };
	glm::vec3 cameraFront { 0, 0, -1.0f };
	glm::vec3 cameraUp { 0, 1.0f, 0 };
	glm::vec3 cameraRight { };
	glm::vec3 worldUp { 0.0f, 1.0f, 0.0f };
	float yaw = -90;
	float pitch = 0.0f;
};

enum class ProjectionType {
	Perspective,
	Orthographic
};

class Renderer {
public:
	Renderer();
	~Renderer();

	void GenerateBuffers(unsigned int& vao, unsigned int& vbo, unsigned int& ebo);

	void BindBuffers(unsigned int& vao, unsigned int& vbo, unsigned int& ebo);

	void ClearBuffers(unsigned int& vbo, unsigned int& ebo);

	void VertexAttributes();

	void GetUniformsLocation();

	void UpdateCamera();

	void SetBufferData(float* vertex, unsigned int vertexAmount, unsigned int* index, unsigned int indexAmount);

	static ShaderSource ParceShader(const std::string_view filepath);

	static void GenerateTexture(Texture& _texture);

	void CreateProgram(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
	
	void DrawTexture(unsigned int& vao, unsigned int indexAmount, glm::mat4 model, Texture _texture);

	void Draw(unsigned int& vao, unsigned int indexAmount, glm::mat4 model);
	
	InternalCamera internalCamera { };

	ProjectionType projectionType { };
private:
	unsigned int CompileShader(unsigned int type, const std::string& source);
	
	unsigned int vao;
	unsigned int vbo;
	unsigned int ebo;
	unsigned int program;

	unsigned int viewLocation;
	unsigned int projLocation;
	unsigned int modelLocation;
	unsigned int typeLocation;
};

#endif // !RENDERER_H
