#include <Hummer.h>

class Sandbox : public Hummer::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{

	}

};

Hummer::Application* Hummer::CreateApplication()
{
	return new Sandbox();
}