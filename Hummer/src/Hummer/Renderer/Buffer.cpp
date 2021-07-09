#include "hmpch.h"
#include "Buffer.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"


namespace Hummer {



	Hummer::Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			HM_CORE_ASSERT(false, "RendererAPI::None is currently not support!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return  CreateRef<OpenGLVertexBuffer>(vertices, size);
		}

		HM_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Hummer::Ref<Hummer::VertexBuffer> VertexBuffer::Create(uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			HM_CORE_ASSERT(false, "RendererAPI::None is currently not support!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return  CreateRef<OpenGLVertexBuffer>(size);
		}

		HM_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Hummer::Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			HM_CORE_ASSERT(false, "RendererAPI::None is currently not support!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return  CreateRef<OpenGLIndexBuffer>(indices, count);
		}

		HM_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
