#pragma once

#include "Core.h"

#include "Window.h"
#include "Hummer/LayerStack.h"
#include "Events/Event.h"
#include "Hummer/Events/ApplicationEvent.h"

#include "Hummer/ImGui/ImGuiLayer.h"

#include "Hummer/Renderer/Shader.h"
#include "Hummer/Renderer/Buffer.h"
#include "Hummer/Renderer/VertexArray.h"

namespace Hummer {

	class HUMMER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();


		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }

		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();

}
