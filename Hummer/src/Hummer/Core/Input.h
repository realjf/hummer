#pragma once

#include "Hummer/Core/Base.h"
#include "Hummer/Core/KeyCodes.h"
#include "Hummer/Core/MouseCodes.h"

#include <glm/glm.hpp>

namespace Hummer {
	class Input
	{
	public:
		static bool IsKeyPressed(const KeyCode keycode);
		static bool IsMouseButtonPressed(const MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
