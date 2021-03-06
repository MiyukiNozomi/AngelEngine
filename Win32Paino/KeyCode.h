#pragma once

namespace AngelEngine {
	struct ButtonState {
		bool isDown;
		bool isUp;
		bool changed;
	};

	enum KeyCode {
		BACKSPACE = 8,
		TAB = 9,
		OFF_NUMPAD5 = 12,

		ENTER = 13,
		SHIFT = 16,
		CTRL = 17,
		ALT = 18,
		PAUSE_OR_BREAK = 19,
		CAPS_LOCK = 20,
		ESCAPE = 32,
		SPACE = 32,
		PAGE_UP = 33,
		PAGE_DOWN = 34,
		END = 35,
		HOME = 36,
		LEFT = 37,
		UP = 38,
		RIGHT = 39,
		DOWN = 40,
		PRINT_SCREEN = 44,
		INSERT = 45,
		AG_DELETE = 46,

		KEY_0 = 48,
		KEY_1 = 49,
		KEY_2 = 50,
		KEY_3 = 51,
		KEY_4 = 52,
		KEY_5 = 53,
		KEY_6 = 54,
		KEY_7 = 55,
		KEY_8 = 56,
		KEY_9 = 57,

		KEY_A = 65,
		KEY_B = 66,
		KEY_C = 67,
		KEY_D = 68,
		KEY_E = 69,
		KEY_F = 70,
		KEY_G = 71,
		KEY_H = 72,
		KEY_I = 73,
		KEY_J = 74,
		KEY_K = 75,
		KEY_L = 76,
		KEY_M = 77,
		KEY_N = 78,
		KEY_O = 79,

		KEY_P = 80,
		KEY_Q = 81,
		KEY_R = 82,
		KEY_S = 83,
		KEY_T = 84,
		KEY_U = 85,
		KEY_V = 86,
		KEY_W = 87,
		KEY_X = 88,
		KEY_Y = 89,
		KEY_Z = 90,
	
		WINDOWS_LEFT = 91,
		WINDOWS_RIGHT = 92,
		POPUP = 93,

		NUMPAD0 = 96,
		NUMPAD1 = 97,
		NUMPAD2 = 98,
		NUMPAD3 = 99,
		NUMPAD4 = 100,
		NUMPAD5 = 101,
		NUMPAD6 = 102,
		NUMPAD7 = 103,
		NUMPAD8 = 104,
		NUMPAD9 = 105,
		MULTIPLY = 106,
		PLUS = 107,
		MINUS = 109,
		DOT = 110,
		DIVIDE = 111,

		F1 = 112,
		F2 = 113,
		F3 = 114,
		F4 = 115,
		F5 = 116,
		F6 = 117,
		F7 = 118,
		F8 = 119,
		F9 = 120,
		F10 = 121,
		F11 = 122,
		F12 = 123,

		NUMLOCK = 144,
		SCROLL_LOCK = 145,
		LEFT_SHIFT = 160,
		RIGHT_SHIFT = 161,
		LEFT_CTRL = 162,
		RIGHT_CTRL = 163,

		BUTTON_COUNT = sizeof(KeyCode) - 1, // i have to manually do this :(
	};
}