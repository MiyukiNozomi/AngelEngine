#pragma once

#include <Windows.h>

#include "Vectors.h"
#include "KeyCode.h"

//change this in case of an emergency :)
#define KEYBOARD_KEY_COUNT 256

namespace AngelEngine {

	class InputSystem {
		public:
			bool GetKeyUp(KeyCode code);
			bool GetKeyDown(KeyCode code);

			static InputSystem& Ref() {
				static InputSystem system;
				return system;
			}
		private:
			InputSystem();
			bool alreadyPressedKeys[KeyCode::BUTTON_COUNT];
	};
	
	static InputSystem& Input = InputSystem::Ref();
}