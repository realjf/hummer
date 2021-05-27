#include "hmpch.h"
#include "Texture.h"


#include "Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"


namespace Hummer
{

	Hummer::Ref<Hummer::Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			HM_CORE_ASSERT(false, "RendererAPI::None is currently not support!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLTexture2D>(path);
		}

		HM_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Hummer::Ref<Hummer::Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			HM_CORE_ASSERT(false, "RendererAPI::None is currently not support!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLTexture2D>(width, height);
		}

		HM_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
