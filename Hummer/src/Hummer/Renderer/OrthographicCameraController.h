#pragma once


#include "Hummer/Renderer/OrthographicCamera.h"
#include "Hummer/Core/TimeStep.h"

#include "Hummer/Events/MouseEvent.h"
#include "Hummer/Events/ApplicationEvent.h"

namespace Hummer
{
	class OrthographicCameraController
	{
	public:
		OrthographicCameraController(float aspectRatio, bool rotation = false);

		void OnUpdate(TimeStep ts);
		void OnEvent(Event& e);

		OrthographicCamera& GetCamera() { return m_Camera; }
		const OrthographicCamera& GetCamera() const { return m_Camera; }

		void SetZoomLevel(float level) { m_ZoomLevel = level; }
		float GetZoomLevel() { return m_ZoomLevel; }
	private:
		bool OnMouseScrolled(MouseScrolledEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);

	private:
		float m_AspectRatio;
		float m_ZoomLevel = 1.0f;
		OrthographicCamera m_Camera;

		bool m_Rotation;
		glm::vec3 m_CameraPosition;
		float m_CameraRotation = 0.0f;

		float m_CameraTranslationSpeed = 1.0f, m_CameraRotationSpeed = 180.0f;
	};
}
