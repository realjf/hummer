#include "hmpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Hummer {
	
	Ref<Shader> Shader::Create(const std::string& filepath)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			HM_CORE_ASSERT(false, "RendererAPI::None is currently not support!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLShader>(filepath);
		}

		HM_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}


	Ref<Shader> Shader::Create(const std::string& name,const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			HM_CORE_ASSERT(false, "RendererAPI::None is currently not support!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return  std::make_shared<OpenGLShader>(name, vertexSrc, fragmentSrc);
		}

		HM_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	void ShaderLibrary::Add(const Ref<Shader>& shader)
	{
		auto& name = shader->GetName();
		HM_CORE_ASSERT(m_Shaders.find(name) == m_Shaders.end(), "Shader already exists!");
		Add(name, shader);
	}

	void ShaderLibrary::Add(const std::string& name, const Ref<Shader>& shader)
	{
		HM_CORE_ASSERT(m_Shaders.find(name) == m_Shaders.end(), "Shader already exists!");
		m_Shaders[name] = shader;
	}

	Hummer::Ref<Hummer::Shader> ShaderLibrary::Load(const std::string& filepath)
	{
		auto shader = Shader::Create(filepath);
		Add(shader);
		return shader;
	}

	Hummer::Ref<Hummer::Shader> ShaderLibrary::Load(const std::string& name, const std::string& filepath)
	{
		auto shader = Shader::Create(filepath);
		Add(name, shader);
		return shader;
	}

	Hummer::Ref<Hummer::Shader> ShaderLibrary::Get(const std::string& name)
	{
		HM_CORE_ASSERT(m_Shaders.find(name) != m_Shaders.end(), "Shader not found!");
		return m_Shaders[name];
	}

	bool ShaderLibrary::Exists(const std::string& name) const
	{
		return m_Shaders.find(name) != m_Shaders.end();
	}

}
