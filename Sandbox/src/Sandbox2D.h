#pragma once

#include "Hummer.h"

class Sandbox2D : public Hummer::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	void OnUpdate(Hummer::TimeStep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Hummer::Event& e) override;

private:
	Hummer::Ref<Hummer::VertexArray> m_SquareVA;
	Hummer::Ref<Hummer::Shader> m_FlatColorShader;

	Hummer::OrthographicCameraController m_CameraController;

	Hummer::Ref<Hummer::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};