#include "Loader.h"

#include <string>

namespace AngelEngine {
	Loader::Loader() {
	}

	AE_Image Loader::LoadImage2D(const char* filename) {
		std::string file = "textures/";
		file += filename;
		AE_Image texture;

		stbi_set_flip_vertically_on_load(true);
		unsigned char* components = stbi_load(file.c_str(), &texture.width, &texture.height, &texture.colorChannelsCount, STBI_rgb_alpha);
		
		texture.pixels.resize(texture.width * texture.height);

		
		//save before modiyfing and deleting it
		unsigned char* c = components;

		for (int y = 0; y < texture.height; y++) {
			for (int x = 0; x < texture.width; x++) {
				Color c;

				c.blue = *components++;
				c.green = *components++;
				c.red = *components++;
				c.alpha = *components++;

				texture.pixels[x * 1 + (texture.width * 1) * y] = c;
			}
		}


		OutputDebugString(L"Successfuly loaded an image!");
		loadedImages.push_back(texture);
		
		free(c);

		return texture;
	}

	void Loader::Release() {
		std::vector<AE_Image>::iterator it;

		OutputDebugString(L"Deleting some of the garbage.");
		
		int d = 0;
		for (it = loadedImages.begin(); it != loadedImages.end(); it++, d++) {
			delete[] loadedImages[d].pixels.data();
		}
	}
}