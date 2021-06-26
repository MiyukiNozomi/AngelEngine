#pragma once

#include <Windows.h>

#include <vector>
#include <string>
#include <stdint.h>

#define toRGB(r,g,b)         ((r)|((g)<<8)|((b)<<16))

#define i32 uint32_t
#define rgb_t uint32_t

namespace AngelEngine {

	struct Color {
		unsigned int red;
		unsigned int green;
		unsigned int blue;
		unsigned int alpha;
	};

	struct AE_Image {
		int width;
		int height;
		int colorChannelsCount;
		std::vector<Color> pixels;

		Color GetPixelAt(int x, int y) {
			return pixels[x * 1 + (width * 1) * y];
		}

		std::vector<AE_Image> toSpriteSheet(int spriteWidth,int spriteHeight) {
			std::vector<AE_Image> sprites;
			int spriteCount = width / spriteWidth;

			sprites.resize(spriteCount);

			for (int x = 0; x < spriteCount; x++) {
				sprites[spriteCount] = subImage(x * spriteWidth, 0, spriteWidth, spriteHeight);
			}

			return sprites;
		}

		AE_Image subImage(int ix, int iy, int iwidth, int iheight) {
			/*std::vector<Color> ipixels;
			
			ipixels.resize(iwidth * iheight);*/



			AE_Image image;
			/*image.width = iwidth;
			image.height = iheight;
			image.pixels = ipixels;*/
			return image;
		}
	};

	struct AE_Bitmap {
		int width;
		int height;
		int size;
		void* pixels;

		AE_Bitmap(int width, int height) {
			this->width = width;
			this->height = height;
		}
		
		void SetPixel(int px, int py, i32 shader) {
			if (!pixels) {
				OutputDebugString(L"WARNING: INVALID BUFFER\n");
				return;
			}
			int x = (width / 2) + px;
			int y = (height / 2) + py;

			if (x < 0 || x > width - 1) 
				return;
			if (y < 0 || y > height - 1)
				return;

			((i32*) pixels)[x * 1 + (width * 1) * y] = shader;
		}

		void Clear(i32 shader) {
			if (!pixels) {
				OutputDebugString(L"WARNING: INVALID BUFFER\n");
				return;
			}

			i32* pixel = (i32*) pixels;
			
			for (int y = 0; y < height; y++) {	
				for (int x = 0; x < width; x++) {
					*pixel++ = shader;
				}
			}
		}
	};

	struct RendererContext : public AE_Bitmap {
		RendererContext(int width, int height) : AE_Bitmap(width,height) {
		}

		void DrawImage(int ix, int iy, AE_Image image) {
			for (int x = 0; x < image.width; x++) {
				for (int y = 0; y < image.height; y++) {
					Color c = image.GetPixelAt(x,y);
					if (c.alpha < 200) {
						continue;
					}
					SetPixel(ix + x, iy + y, toRGB(c.red, c.green, c.blue));
				}
			}
		}
	};
}