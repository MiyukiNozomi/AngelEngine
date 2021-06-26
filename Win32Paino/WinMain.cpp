#include <Windows.h>

#include "AngelEngine.h"

static bool running = true;

LRESULT CALLBACK WindowCallback(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
		case WM_DESTROY:
			running = false;
			break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {

	WNDCLASS wc = {};

	wc.lpfnWndProc = WindowCallback;
	wc.lpszClassName = L"AngelEngineClass";
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClass(&wc)) {
		//TODO show error: unable to register class :P
		return -1;
	}

	HWND hwnd = CreateWindow(
		wc.lpszClassName, L"Angel Engine" ,
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, Window_Width, Window_Height, 0, 0, hInstance, nullptr
	);

	if (!hwnd) {
		//TODO show error: unable to create an HWND.
		return -1;
	}

	UpdateWindow(hwnd);

	AngelEngine::Engine.Init(hwnd);

	MSG msg;

	while (running) {
		if (PeekMessage(&msg, hwnd, 0, 0, PM_REMOVE)) {
			DispatchMessage(&msg);
			TranslateMessage(&msg);

			if (msg.message == WM_QUIT)
				break;
		}

		AngelEngine::Engine.Update();
		AngelEngine::Engine.Render();
	}

	AngelEngine::Engine.Release();

	return 0;
}