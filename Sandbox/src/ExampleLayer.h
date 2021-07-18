#pragma once
#include "Hummer.h"

#include "Platform/OpenGL/OpenGLShader.h"
#include "ImGui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ExampleLayer : public Hummer::Layer
{
public:
	ExampleLayer();
	~ExampleLayer() {};

	void OnAttach();
	void OnDetach();
	void OnUpdate(Hummer::TimeStep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Hummer::Event& e) override;

private:
	Hummer::ShaderLibrary m_ShaderLibrary;
	Hummer::Ref<Hummer::Shader> m_Shader;
	Hummer::Ref<Hummer::VertexArray> m_VertexArray;

	Hummer::Ref<Hummer::Shader> m_FlatColorShader;
	Hummer::Ref<Hummer::VertexArray> m_SquareVA;

	Hummer::Ref<Hummer::Texture2D> m_Texture;
	Hummer::Ref<Hummer::Texture2D> m_RealJFTexture;

	Hummer::OrthographicCameraController m_CameraController;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};
