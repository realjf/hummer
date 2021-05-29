#pragma once

#include "Hummer/Core/Layer.h"

#include "Hummer/Events/KeyEvent.h"
#include "Hummer/Events/MouseEvent.h"
#include "Hummer/Events/ApplicationEvent.h"

namespace Hummer {

	class HUMMER_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}

