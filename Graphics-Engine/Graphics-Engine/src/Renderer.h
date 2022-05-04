#ifndef RENDERER_H
#define RENDERER_H

#include "Input.h"
#include "ShaderSource.h"
#include "Transform.h"
#include "TextureImporter.h"
#include <fstream>
#include <sstream>

struct Material {
	glm::vec4 color{ 1.0f, 1.0f, 1.0f, 1.0f };
	glm::vec3 ambient{ 1.0f, 0.5f, 0.31f };
	glm::vec3 diffuse{ 1.0f, 0.5f, 0.31f };
	glm::vec3 specular{ 0.5f, 0.5f, 0.5f };
	float shininess = 32.0f;
};

struct LightingMap {
	glm::vec4 color{ 1.0f, 1.0f, 1.0f, 1.0f };
	glm::vec3 ambient{ 1.0f, 0.5f, 0.31f };
	Texture diffuse{};
	Texture specular{};
	float shininess = 32.0f;
};

struct LightData {
	LightData(glm::vec3 _position, float r, float g, float b) {
		position = _position;
		lightColor = {r, g, b};

		diffuse = lightColor * glm::vec3(0.5f);
		ambient = diffuse * glm::vec3(0.2f);
	}

	glm::vec3 lightColor;
	glm::vec3 position;

	glm::vec3 ambient{};
	glm::vec3 diffuse{};
	glm::vec3 specular{ 1.0f, 1.0f, 1.0f };
};

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

	void SetLight(LightData& light);

	void SetBufferData(float* vertex, unsigned int vertexAmount, unsigned int* index, unsigned int indexAmount);

	static ShaderSource ParceShader(const std::string_view filepath);

	static void GenerateTexture(Texture& _texture);

	void CreateProgram(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
	
	void DrawTexture(unsigned int& vao, unsigned int indexAmount, glm::mat4 model, LightingMap& lightingMap);

	void Draw(unsigned int& vao, unsigned int indexAmount, glm::mat4 model, Material& material);
	
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
	unsigned int viewPosLocation;
};

#endif // !RENDERER_H
