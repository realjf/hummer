#include <Hummer.h>

class ExampleLayer : public Hummer::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	~ExampleLayer() {}

	void OnUpdate() override
	{
		if (Hummer::Input::IsKeyPressed(HM_KEY_TAB))
			HM_TRACE("Tab key is pressed!");
	}

	void OnAttach()
	{

	}

	void OnDetach()
	{
	}

	void OnEvent(Hummer::Event& event) override
	{
		HM_TRACE("{0}", event);
	}
};

class Sandbox : public Hummer::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Hummer::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

Hummer::Application* Hummer::CreateApplication()
{
	return new Sandbox();
}