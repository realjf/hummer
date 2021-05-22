#include "hmpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Hummer {
	
	Shader* Shader::Create(const std::string& filepath)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			HM_CORE_ASSERT(false, "RendererAPI::None is currently not support!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return new OpenGLShader(filepath);
		}

		HM_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}


	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			HM_CORE_ASSERT(false, "RendererAPI::None is currently not support!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return new OpenGLShader(vertexSrc, fragmentSrc);
		}

		HM_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}
