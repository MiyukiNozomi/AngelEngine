#pragma once

#include <Windows.h>

#include <vector>
#include "Buffers.h"
#include "stb_image.h"

#define ANGELENGINE_TEXTURES_FOLDER "textures/"

namespace AngelEngine {
	class Loader {
		public:
			AE_Image LoadImage2D(const char* filename);

			void Release();

			static Loader& Ref() {
				static Loader loader;
				return loader;
			}
		private:
			Loader();
			
			std::vector<AE_Image> loadedImages;
	};

	static Loader& GraphicalLoader = Loader::Ref();
}