#include <Hummer.h>

#include "Platform/OpenGL/OpenGLShader.h"
#include "ImGui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class ExampleLayer : public Hummer::Layer
{
public:
	ExampleLayer() : Layer("ExampleLayer") , m_Camera(-1.0f, 1.0f, -1.0f, 1.0f), m_CameraPosition(0.0f)
	{
		m_VertexArray.reset(Hummer::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
			0.0f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f
		};

		std::shared_ptr<Hummer::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Hummer::VertexBuffer::Create(vertices, sizeof(vertices)));

		Hummer::BufferLayout layout = {
			{ Hummer::ShaderDataType::Float3, "a_Position" },
			{ Hummer::ShaderDataType::Float4, "a_Color" },
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		unsigned int indices[3] = { 0, 1, 2 };
		std::shared_ptr<Hummer::IndexBuffer> indexBuffer;
		indexBuffer.reset(Hummer::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(Hummer::VertexArray::Create());
		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
		};

		std::shared_ptr<Hummer::VertexBuffer> squareVB;
		squareVB.reset(Hummer::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));

		squareVB->SetLayout({
			{ Hummer::ShaderDataType::Float3, "a_Position" },
			{ Hummer::ShaderDataType::Float2, "a_TexCoord" }
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		unsigned int squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<Hummer::IndexBuffer> squareIB;
		squareIB.reset(Hummer::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);


		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";

		m_Shader = Hummer::Shader::Create("VertexPosColor", vertexSrc, fragmentSrc);

		std::string flatShaderVertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

		std::string flatShaderFragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			uniform vec3 u_Color;

			void main()
			{
				color = vec4(u_Color, 1.0f);
			}
		)";

		m_FlatColorShader = Hummer::Shader::Create("FlatColor", flatShaderVertexSrc, flatShaderFragmentSrc);

		auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

		m_Texture = Hummer::Texture2D::Create("assets/textures/Checkerboard.png");
		m_RealJFTexture = Hummer::Texture2D::Create("assets/textures/realjf_logo.png");
		std::dynamic_pointer_cast<Hummer::OpenGLShader>(textureShader)->Bind();
		std::dynamic_pointer_cast<Hummer::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", 0);
		
	}
	~ExampleLayer() {};

	void OnAttach() {};

	void OnDetach() {};

	void OnUpdate(Hummer::TimeStep ts) override
	{

		HM_TRACE("Delta time: {0}S ({1}ms)", ts.GetSeconds(), ts.GetMilliseconds());
		if (Hummer::Input::IsKeyPressed(HM_KEY_LEFT))
			m_CameraPosition.x += m_CameraMoveSpeed * ts;
		else if (Hummer::Input::IsKeyPressed(HM_KEY_RIGHT))
			m_CameraPosition.x -= m_CameraMoveSpeed * ts;
		if (Hummer::Input::IsKeyPressed(HM_KEY_DOWN))
			m_CameraPosition.y += m_CameraMoveSpeed * ts;
		else if (Hummer::Input::IsKeyPressed(HM_KEY_UP))
			m_CameraPosition.y -= m_CameraMoveSpeed * ts;

		if (Hummer::Input::IsKeyPressed(HM_KEY_A))
			m_CameraRotation -= m_CameraRotationSpeed * ts;
		if (Hummer::Input::IsKeyPressed(HM_KEY_D))
			m_CameraRotation += m_CameraRotationSpeed * ts;

		Hummer::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Hummer::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Hummer::Renderer::BeginScene(m_Camera);

	
		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		std::dynamic_pointer_cast<Hummer::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<Hummer::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				Hummer::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
			}
		}

		auto textureShader = m_ShaderLibrary.Get("Texture");

		m_Texture->Bind();
		Hummer::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
		m_RealJFTexture->Bind();
		Hummer::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
		//Hummer::Renderer::Submit(m_Shader, m_VertexArray);

		Hummer::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));

		ImGui::End();
	}

	void OnEvent(Hummer::Event& event)
	{

	}

private:
	Hummer::ShaderLibrary m_ShaderLibrary;
	Hummer::Ref<Hummer::Shader> m_Shader;
	Hummer::Ref<Hummer::VertexArray> m_VertexArray;

	Hummer::Ref<Hummer::Shader> m_FlatColorShader;
	Hummer::Ref<Hummer::VertexArray> m_SquareVA;

	Hummer::Ref<Hummer::Texture2D> m_Texture;
	Hummer::Ref<Hummer::Texture2D> m_RealJFTexture;

	Hummer::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 10.0f;
	float m_CameraMoveSpeed = 0.1f;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

class Sandbox : public Hummer::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Hummer::Application* Hummer::CreateApplication()
{
	return new Sandbox();
}