#pragma once

#define Window_Width 820
#define Window_Height 520

#include <Windows.h>
#include <vector>

#include "KeyCode.h"
#include "Input.h"
#include "Buffers.h"
#include "Loader.h"

namespace AngelEngine {
	class AngelEngine {
		public:

			void Init(HWND hwnd);
			void Update();
			void Render();
			void Release();

			static AngelEngine& Ref() {
				static AngelEngine ref;
				return ref;
			}

		private:
			HDC hdc;

			int viewportWidth;
			int viewportHeight;

			RendererContext* bitmap;
			BITMAPINFO bitmapInfo;

			std::vector<AE_Image> spriteSheet;
		private:
			AngelEngine();
	};

	static AngelEngine& Engine = AngelEngine::Ref();
}