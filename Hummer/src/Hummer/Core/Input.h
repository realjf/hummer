#pragma once

#include "Hummer/Core/Core.h"
#include "Hummer/Core/KeyCodes.h"
#include "Hummer/Core/MouseCodes.h"

#include <glm/glm.hpp>

namespace Hummer {
	class HUMMER_API Input
	{
	public:
		static bool IsKeyPressed(const KeyCode keycode);
		static bool IsMouseButtonPressed(const MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
