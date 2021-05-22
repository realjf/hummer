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
			return std::make_shared<OpenGLTexture2D>(path);
		}

		HM_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
