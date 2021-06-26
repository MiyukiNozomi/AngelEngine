#include "Input.h"

namespace AngelEngine {
	InputSystem::InputSystem() {
	}

	bool InputSystem::GetKeyDown(KeyCode key) {
		return (GetKeyState(key) < 0);
	}

	bool InputSystem::GetKeyUp(KeyCode key) {
		if (GetKeyDown(key)) {
			if (!alreadyPressedKeys[key]) {
				alreadyPressedKeys[key] = true;
				return true;
			} 
		} else {
			alreadyPressedKeys[key] = false;
		}
		return false;
	}
}