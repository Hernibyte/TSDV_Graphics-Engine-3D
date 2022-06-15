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

	inline static unsigned int ImportFromFile(const char* path, const std::string& directory, bool gamma) {
        std::string filename = std::string(path);
        filename = directory + '/' + filename;

        unsigned int textureID;
        glGenTextures(1, &textureID);

        int width, height, nrComponents;
        unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
        if (data)
        {
            GLenum format;
            if (nrComponents == 1)
                format = GL_RED;
            else if (nrComponents == 3)
                format = GL_RGB;
            else if (nrComponents == 4)
                format = GL_RGBA;

            glBindTexture(GL_TEXTURE_2D, textureID);
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

            stbi_image_free(data);
        }
        else
        {
            std::cout << "Texture failed to load at path: " << path << std::endl;
            stbi_image_free(data);
        }

        return textureID;
	}
};

#endif // !TEXTUREIMPORTER_H
