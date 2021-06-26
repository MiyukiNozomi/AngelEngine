#include "AngelEngine.h"

namespace AngelEngine {
	AngelEngine::AngelEngine() {
	}

	void AngelEngine::Init(HWND hwnd) {
		RECT rect;
		GetClientRect(hwnd, &rect);

		this->viewportWidth = rect.right - rect.left;
		this->viewportHeight = rect.bottom - rect.top;

		bitmap = new RendererContext(this->viewportWidth / 2, this->viewportHeight / 2);

		bitmap->size = bitmap->width * bitmap->height * 4;

		bitmap->pixels = VirtualAlloc(0, bitmap->width * bitmap->height * 4, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
		
		bitmapInfo.bmiHeader.biSize = sizeof(bitmapInfo.bmiHeader);
		bitmapInfo.bmiHeader.biWidth = bitmap->width;
		bitmapInfo.bmiHeader.biHeight = bitmap->height;
		bitmapInfo.bmiHeader.biPlanes = 1;
		bitmapInfo.bmiHeader.biBitCount = 32;
		bitmapInfo.bmiHeader.biCompression = BI_RGB;

		this->hdc = GetDC(hwnd);

		AE_Image testImage = GraphicalLoader.LoadImage2D("test_character.png");
		this->spriteSheet = testImage.toSpriteSheet(25,47);
	}

	void AngelEngine::Update() {

	}

	void AngelEngine::Render() {
		bitmap->Clear(0xFFFFFF);

		bitmap->DrawImage(30, 20,this->spriteSheet[0]);
		
		StretchDIBits(hdc, 0, 0, viewportWidth, viewportHeight, 0, 0, bitmap->width, bitmap->height, bitmap->pixels, &bitmapInfo, DIB_RGB_COLORS, SRCCOPY);
	}

	void AngelEngine::Release() {
		if (bitmap->pixels) {
			VirtualFree(bitmap->pixels, 0, MEM_RELEASE);
		}
	}
}