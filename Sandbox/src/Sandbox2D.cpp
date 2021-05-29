#include "Sandbox2D.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f, true)
{

}

void Sandbox2D::OnAttach()
{
	HM_PROFILE_FUNCTION();
	m_CheckerboardTexture = Hummer::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
	HM_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Hummer::TimeStep ts)
{
	HM_PROFILE_FUNCTION();
	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	{
		HM_PROFILE_SCOPE("Renderer Prep");
		Hummer::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Hummer::RenderCommand::Clear();
	}

	{
		HM_PROFILE_SCOPE("Renderer Draw");
		Hummer::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Hummer::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Hummer::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.2f, 0.8f, 1.0f });
		Hummer::Renderer2D::DrawQuad({ 0.2f, 0.5f }, { 10.0f, 10.0f }, m_CheckerboardTexture);

		Hummer::Renderer2D::EndScene();
	}

}

void Sandbox2D::OnImGuiRender()
{
	HM_PROFILE_FUNCTION();
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));

	ImGui::End();
}

void Sandbox2D::OnEvent(Hummer::Event& e)
{
	m_CameraController.OnEvent(e);
}
