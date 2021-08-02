#pragma once

#include "Hummer/Core/Layer.h"

#include "Hummer/Events/KeyEvent.h"
#include "Hummer/Events/MouseEvent.h"
#include "Hummer/Events/ApplicationEvent.h"

namespace Hummer {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }

		void SetDarkThemeColors();

	private:
		bool m_BlockEvents = true;
	};

}

