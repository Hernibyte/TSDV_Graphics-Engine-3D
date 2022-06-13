#include "Renderer.h"

Renderer::Renderer() {
	program = 0;
	vao = 0;
	vbo = 0;
	ebo = 0;

	modelLocation = 0;
	typeLocation = 0;
	viewLocation = 0;
	projLocation = 0;
}

Renderer::~Renderer() {
	
}

void Renderer::GenerateBuffers(unsigned int& vao, unsigned int& vbo, unsigned int& ebo) {
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);
}

void Renderer::BindBuffers(unsigned int& vao, unsigned int& vbo, unsigned int& ebo) {
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
}

void Renderer::ClearBuffers(unsigned int& vbo, unsigned int& ebo) {
	glClearBufferData(GL_ARRAY_BUFFER, GL_RGB32F, GL_RGB, GL_FLOAT, &vbo);
	glClearBufferData(GL_ELEMENT_ARRAY_BUFFER, GL_RGBA8, GL_RGB, GL_UNSIGNED_INT, &ebo);
}

void Renderer::SetBufferData(float* vertex, unsigned int vertexAmount, unsigned int* index, unsigned int indexAmount) {
	glBufferData(GL_ARRAY_BUFFER,
		vertexAmount * sizeof(vertex), vertex,
		GL_DYNAMIC_DRAW);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		indexAmount * sizeof(index), index,
		GL_DYNAMIC_DRAW);
}

void Renderer::VertexAttributes() {
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
}

void Renderer::GetUniformsLocation() {
	modelLocation = glGetUniformLocation(program, "model");
	typeLocation = glGetUniformLocation(program, "type");
	viewLocation = glGetUniformLocation(program, "view");
	projLocation = glGetUniformLocation(program, "projection");
	viewPosLocation = glGetUniformLocation(program, "viewPos");
}

void Renderer::UpdateCamera() {
	internalCamera.view = glm::lookAt(
		internalCamera.cameraPos,
		internalCamera.cameraPos + internalCamera.cameraFront,
		internalCamera.cameraUp
	);
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(internalCamera.view));

	switch (projectionType) {
	case ProjectionType::Orthographic:
		internalCamera.projection = glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f);
		break;
	case ProjectionType::Perspective:
		internalCamera.projection = glm::perspective(glm::radians(45.0f), 1280.0f / 720.0f, 0.1f, 100.0f);
		break;
	}
	glUniformMatrix4fv(projLocation, 1, GL_FALSE, glm::value_ptr(internalCamera.projection));
}

void Renderer::DrawLights() {
	if (directionalLight != nullptr) {
		glUniform3fv(glGetUniformLocation(program, "directionalLight.direction"), 1, &directionalLight->direction[0]);
		glUniform3fv(glGetUniformLocation(program, "directionalLight.ambient"), 1, &directionalLight->ambient[0]);
		glUniform3fv(glGetUniformLocation(program, "directionalLight.diffuse"), 1, &directionalLight->diffuse[0]);
		glUniform3fv(glGetUniformLocation(program, "directionalLight.specular"), 1, &directionalLight->specular[0]);
		glUniform1i(glGetUniformLocation(program, "directionalLight.lightIsSet"), directionalLight->lightIsSet);
	}
	// point light
	if (pointLights[0] != nullptr) {
		glUniform3fv(glGetUniformLocation(program, "pointLights[0].position"), 1, &pointLights[0]->position[0]);
		glUniform1f(glGetUniformLocation(program, "pointLights[0].constant"), pointLights[0]->constant);
		glUniform1f(glGetUniformLocation(program, "pointLights[0].linear"), pointLights[0]->linear);
		glUniform1f(glGetUniformLocation(program, "pointLights[0].quadratic"), pointLights[0]->quadratic);
		glUniform3fv(glGetUniformLocation(program, "pointLights[0].ambient"), 1, &pointLights[0]->ambient[0]);
		glUniform3fv(glGetUniformLocation(program, "pointLights[0].diffuse"), 1, &pointLights[0]->diffuse[0]);
		glUniform3fv(glGetUniformLocation(program, "pointLights[0].specular"), 1, &pointLights[0]->specular[0]);
		glUniform1i(glGetUniformLocation(program, "pointLights[0].lightIsSet"), pointLights[0]->lightIsSet);
	}

	if (pointLights[1] != nullptr) {
		glUniform3fv(glGetUniformLocation(program, "pointLights[1].position"), 1, &pointLights[1]->position[0]);
		glUniform1f(glGetUniformLocation(program, "pointLights[1].constant"), pointLights[1]->constant);
		glUniform1f(glGetUniformLocation(program, "pointLights[1].linear"), pointLights[1]->linear);
		glUniform1f(glGetUniformLocation(program, "pointLights[1].quadratic"), pointLights[1]->quadratic);
		glUniform3fv(glGetUniformLocation(program, "pointLights[1].ambient"), 1, &pointLights[1]->ambient[0]);
		glUniform3fv(glGetUniformLocation(program, "pointLights[1].diffuse"), 1, &pointLights[1]->diffuse[0]);
		glUniform3fv(glGetUniformLocation(program, "pointLights[1].specular"), 1, &pointLights[1]->specular[0]);
		glUniform1i(glGetUniformLocation(program, "pointLights[1].lightIsSet"), pointLights[1]->lightIsSet);
	}

	if (pointLights[2] != nullptr) {
		glUniform3fv(glGetUniformLocation(program, "pointLights[2].position"), 1, &pointLights[2]->position[0]);
		glUniform1f(glGetUniformLocation(program, "pointLights[2].constant"), pointLights[2]->constant);
		glUniform1f(glGetUniformLocation(program, "pointLights[2].linear"), pointLights[2]->linear);
		glUniform1f(glGetUniformLocation(program, "pointLights[2].quadratic"), pointLights[2]->quadratic);
		glUniform3fv(glGetUniformLocation(program, "pointLights[2].ambient"), 1, &pointLights[2]->ambient[0]);
		glUniform3fv(glGetUniformLocation(program, "pointLights[2].diffuse"), 1, &pointLights[2]->diffuse[0]);
		glUniform3fv(glGetUniformLocation(program, "pointLights[2].specular"), 1, &pointLights[2]->specular[0]);
		glUniform1i(glGetUniformLocation(program, "pointLights[2].lightIsSet"), pointLights[2]->lightIsSet);
	}
	if (pointLights[3] != nullptr) {
		glUniform3fv(glGetUniformLocation(program, "pointLights[3].position"), 1, &pointLights[3]->position[0]);
		glUniform1f(glGetUniformLocation(program, "pointLights[3].constant"), pointLights[3]->constant);
		glUniform1f(glGetUniformLocation(program, "pointLights[3].linear"), pointLights[3]->linear);
		glUniform1f(glGetUniformLocation(program, "pointLights[3].quadratic"), pointLights[3]->quadratic);
		glUniform3fv(glGetUniformLocation(program, "pointLights[3].ambient"), 1, &pointLights[3]->ambient[0]);
		glUniform3fv(glGetUniformLocation(program, "pointLights[3].diffuse"), 1, &pointLights[3]->diffuse[0]);
		glUniform3fv(glGetUniformLocation(program, "pointLights[3].specular"), 1, &pointLights[3]->specular[0]);
		glUniform1i(glGetUniformLocation(program, "pointLights[3].lightIsSet"), pointLights[3]->lightIsSet);
	}
	//

	if (spotLight != nullptr) {
		glUniform3fv(glGetUniformLocation(program, "spotLight.position"), 1, &spotLight->position[0]);
		glUniform3fv(glGetUniformLocation(program, "spotLight.direction"), 1, &spotLight->direction[0]);
		glUniform1f(glGetUniformLocation(program, "spotLight.cutOff"), spotLight->cutOff);
		glUniform1f(glGetUniformLocation(program, "spotLight.outerCutOff"), spotLight->outerCutOff);
		glUniform1f(glGetUniformLocation(program, "spotLight.constant"), spotLight->constant);
		glUniform1f(glGetUniformLocation(program, "spotLight.linear"), spotLight->linear);
		glUniform1f(glGetUniformLocation(program, "spotLight.quadratic"), spotLight->quadratic);
		glUniform3fv(glGetUniformLocation(program, "spotLight.ambient"), 1, &spotLight->ambient[0]);
		glUniform3fv(glGetUniformLocation(program, "spotLight.diffuse"), 1, &spotLight->diffuse[0]);
		glUniform3fv(glGetUniformLocation(program, "spotLight.specular"), 1, &spotLight->specular[0]);
		glUniform1i(glGetUniformLocation(program, "spotLight.lightIsSet"), spotLight->lightIsSet);
	}
}

void Renderer::SetDirectionalLight(DirectionalLightData& dirLight) {
	directionalLight = &dirLight;
	directionalLight->lightIsSet = 1;
}

void Renderer::AddPointLight(PointLightData& pointLight, int lNumber) {
	pointLights[lNumber] = &pointLight;
	pointLights[lNumber]->lightIsSet = 1;
}

void Renderer::SetSpotLight(SpotLightData& _spotLight) {
	spotLight = &_spotLight;
	spotLight->lightIsSet = 1;
}

void Renderer::DrawMesh(unsigned int& vao, unsigned int indexAmount, glm::mat4 model, LightingMap& lightingMap, std::vector<Texture> textures) {
	glUniform1i(typeLocation, 1);

	DrawLights();

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textures[0].texture);

	glUniformMatrix4fv(modelLocation, 1, GL_FALSE,
		glm::value_ptr(model));

	glUniform4fv(glGetUniformLocation(program, "material.color"), 1, &lightingMap.color[0]);
	glUniform3fv(glGetUniformLocation(program, "material.ambient"), 1, &lightingMap.ambient[0]);
	glUniform1f(glGetUniformLocation(program, "material.shininess"), lightingMap.shininess);

	glUniform3fv(viewPosLocation, 1, &internalCamera.cameraPos[0]);

	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, indexAmount, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Renderer::DrawTexture(unsigned int& vao, unsigned int indexAmount, glm::mat4 model, LightingMap& lightingMap) {
	glUniform1i(typeLocation, 1);
	
	DrawLights();

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, lightingMap.diffuse.texture);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, lightingMap.specular.texture);

	glUniformMatrix4fv(modelLocation, 1, GL_FALSE,
		glm::value_ptr(model));

	glUniform4fv(glGetUniformLocation(program, "material.color"), 1, &lightingMap.color[0]);
	glUniform3fv(glGetUniformLocation(program, "material.ambient"), 1, &lightingMap.ambient[0]);
	glUniform1f(glGetUniformLocation(program, "material.shininess"), lightingMap.shininess);

	glUniform3fv(viewPosLocation, 1, &internalCamera.cameraPos[0]);

	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, indexAmount, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Renderer::Draw(unsigned int& vao, unsigned int indexAmount, glm::mat4 model, Material& material) {
	glUniform1i(typeLocation, 0);

	DrawLights();

	glUniformMatrix4fv(modelLocation, 1, GL_FALSE,
		glm::value_ptr(model));

	glUniform4fv(glGetUniformLocation(program, "material.color"), 1, &material.color[0]);
	glUniform3fv(glGetUniformLocation(program, "material.ambient"), 1, &material.ambient[0]);
	glUniform3fv(glGetUniformLocation(program, "material.diffuse"), 1, &material.diffuse[0]);
	glUniform3fv(glGetUniformLocation(program, "material.specular"), 1, &material.specular[0]);
	glUniform1f(glGetUniformLocation(program, "material.shininess"), material.shininess);

	glUniform3fv(viewPosLocation, 1, &internalCamera.cameraPos[0]);

	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, indexAmount, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Renderer::GenerateTexture(Texture& _texture) {
	glGenTextures(1, &_texture.texture);
	glBindTexture(GL_TEXTURE_2D, _texture.texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (_texture.data) {
		switch (_texture.type) {
		case TextureType::RGB:
			glTexImage2D(
				GL_TEXTURE_2D, 0,
				GL_RGB, _texture.width,
				_texture.height, 0, GL_RGB,
				GL_UNSIGNED_BYTE, _texture.data);
			break;
		case TextureType::RGBA:
			glTexImage2D(
				GL_TEXTURE_2D, 0,
				GL_RGBA, _texture.width,
				_texture.height, 0, GL_RGBA,
				GL_UNSIGNED_BYTE, _texture.data);
			break;
		}
		glGenerateMipmap(GL_TEXTURE_2D);
	}
}

ShaderSource Renderer::ParceShader(const std::string_view filepath) {
	std::ifstream stream(filepath.data());

	enum class ShaderType {
		NONE = -1,
		VERTEX,
		FRAGMENT
	};

	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;
	while (std::getline(stream, line)) {
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos)
				type = ShaderType::VERTEX;
			else if (line.find("fragment") != std::string::npos)
				type = ShaderType::FRAGMENT;
		}
		else
			ss[(int)type] << line << '\n';
	}

	return {
		ss[0].str(),
		ss[1].str()
	};
}

unsigned int Renderer::CompileShader(unsigned int type, const std::string& source) {
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);
	//
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)_malloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}
	//
	return id;
}

void Renderer::CreateProgram(const std::string& vertexShaderSource, const std::string& fragmentShaderSource) {
	program = glCreateProgram();
	unsigned int vertex = CompileShader(GL_VERTEX_SHADER, vertexShaderSource);
	unsigned int fragment = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glLinkProgram(program);
	glValidateProgram(program);
	glUseProgram(program);

	glDetachShader(program, vertex);
	glDetachShader(program, fragment);
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}