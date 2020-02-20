#pragma once

#include "Core.h"

namespace Hummer {

	class HUMMER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

