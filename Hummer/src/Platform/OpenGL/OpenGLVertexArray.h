#pragma once

#include "Hummer/Renderer/VertexArray.h"

namespace Hummer {

	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();



		virtual void Bind() const override;
		virtual void UnBind() const override;

		virtual void AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer);
		virtual void SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer);

		virtual const std::vector<Ref<VertexBuffer>>& GetVertexBuffers() const { return m_VertexBuffers; };
		virtual const Ref<IndexBuffer>& GetIndexBuffer() const { return m_IndexBuffer; };
	private:
		uint32_t m_RendererID;
		std::vector<Ref<VertexBuffer>> m_VertexBuffers;
		Ref<IndexBuffer> m_IndexBuffer;
	};

}


