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
		GL_STATIC_DRAW);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		indexAmount * sizeof(index), index,
		GL_STATIC_DRAW);
}

void Renderer::VertexAttributes() {
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(7 * sizeof(float)));
	glEnableVertexAttribArray(2);
}

void Renderer::GetUniformsLocation() {
	modelLocation = glGetUniformLocation(program, "model");
	typeLocation = glGetUniformLocation(program, "type");
	viewLocation = glGetUniformLocation(program, "view");
	projLocation = glGetUniformLocation(program, "projection");
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

void Renderer::DrawTexture(unsigned int& vao, unsigned int indexAmount, glm::mat4 model, Texture _texture) {
	glUniform1i(typeLocation, 1);
	
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _texture.texture);
	
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE,
		glm::value_ptr(model));

	glDrawElements(GL_TRIANGLES, indexAmount, GL_UNSIGNED_INT, 0);
}

void Renderer::Draw(unsigned int& vao, unsigned int indexAmount, glm::mat4 model) {
	glUniform1i(typeLocation, 0);

	glUniformMatrix4fv(modelLocation, 1, GL_FALSE,
		glm::value_ptr(model));

	glDrawElements(GL_TRIANGLES, indexAmount, GL_UNSIGNED_INT, 0);
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