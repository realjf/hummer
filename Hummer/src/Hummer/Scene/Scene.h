#pragma once

#include "entt.hpp"

#include "Hummer/Core/TimeStep.h"

namespace Hummer {

	class Scene {
	public:
		Scene();
		~Scene();


		void OnUpdate(TimeStep ts);
	private:
		entt::registry m_Registry;
	};
}