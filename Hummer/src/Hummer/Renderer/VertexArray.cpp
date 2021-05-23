#include "hmpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Hummer {
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			HM_CORE_ASSERT(false, "RendererAPI::None is currently not support!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLVertexArray>();
		}

		HM_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}
