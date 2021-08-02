#pragma once

#include "Base.h"

#include "Window.h"
#include "Hummer/Core/LayerStack.h"
#include "Hummer/Events/Event.h"
#include "Hummer/Events/ApplicationEvent.h"

#include "Hummer/Core/TimeStep.h"

#include "Hummer/ImGui/ImGuiLayer.h"


namespace Hummer {

	class Application
	{
	public:
		Application(const std::string& name = "Hummer App");
		virtual ~Application();

		void Run();


		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }

		inline Window& GetWindow() { return *m_Window; }

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		TimeStep m_TimeStep;
		float m_LastFrameTime = 0.0f;
		bool m_Minimized = false;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();

}
