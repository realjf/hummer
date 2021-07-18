#include <Hummer.h>

#include <Hummer/Core/EntryPoint.h>

#include "Sandbox2D.h"

class Sandbox : public Hummer::Application
{
public:
	Sandbox()
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{

	}

};

Hummer::Application* Hummer::CreateApplication()
{
	return new Sandbox();
}