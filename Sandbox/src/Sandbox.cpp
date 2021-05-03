#include <Hummer.h>

class ExampleLayer : public Hummer::Layer
{
public:
	ExampleLayer() : Layer("ExampleLayer") {}
	~ExampleLayer() {};

	void OnAttach() {};

	void OnDetach() {};

	void OnUpdate()
	{
		if (Hummer::Input::IsKeyPressed(HM_KEY_TAB))
			HM_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Hummer::Event& event)
	{
		if (event.GetEventType() == Hummer::EventType::KeyPressed)
		{
			Hummer::KeyPressedEvent& e = (Hummer::KeyPressedEvent&)event;
			if (e.GetKeyCode() == HM_KEY_TAB)
				HM_TRACE("Tab key is pressed (event)!");
			HM_TRACE("{0}", (char)e.GetKeyCode());
		}
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