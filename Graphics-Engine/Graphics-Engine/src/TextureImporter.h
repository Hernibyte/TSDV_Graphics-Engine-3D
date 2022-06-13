#ifndef TEXTUREIMPORTER_H
#define TEXTUREIMPORTER_H

#include "stb_image.h"
#include <iostream>
#include "Export.h"

enum class ENGINE_API TextureType {
	RGB = 0,
	RGBA = 1
};

struct ENGINE_API Texture {
	unsigned int texture;
	unsigned char* data;
	int width;
	int height;
	int nrChannels;
	TextureType type;
	std::string path;
	std::string txType;
};
 
class TextureImporter {
public:
	inline static void Import(const char* file_path, TextureType type, Texture& tex) {
		stbi_set_flip_vertically_on_load(true);

		tex.data = stbi_load(file_path, &tex.width, &tex.height, &tex.nrChannels, 0);
		tex.type = type;

		if (!tex.data)
			std::cout << "No texture load" << std::endl;
	}
};

#endif // !TEXTUREIMPORTER_H
