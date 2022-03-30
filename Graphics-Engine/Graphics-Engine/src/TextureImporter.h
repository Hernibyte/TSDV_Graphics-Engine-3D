#ifndef TEXTUREIMPORTER_H
#define TEXTUREIMPORTER_H

#include "stb_image.h"
#include <iostream>

enum class TextureType {
	RGB = 0,
	RGBA = 1
};

struct Texture {
	unsigned int texture;
	unsigned char* data;
	int width;
	int height;
	int nrChannels;
	TextureType type;
};

class TextureImporter {
public:
	inline static Texture Import(const char* file_path, TextureType type, Texture tex) {
		Texture aux;

		stbi_set_flip_vertically_on_load(true);

		aux.data = stbi_load(file_path, &tex.width, &tex.height, &tex.nrChannels, 0);
		aux.type = type;

		return aux;
	}
};

#endif // !TEXTUREIMPORTER_H
