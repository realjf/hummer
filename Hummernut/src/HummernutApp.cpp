#include <Hummer.h>

#include <Hummer/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Hummer {
	class Hummernut : public Application
	{
	public:
		Hummernut()
			: Application("Hummer Editor")
		{
			//PushLayer(new ExampleLayer());
			PushLayer(new EditorLayer());
		}

		~Hummernut()
		{

		}

	};

	Application* CreateApplication()
	{
		return new Hummernut();
	}

}