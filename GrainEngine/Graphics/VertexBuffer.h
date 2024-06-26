#pragma once

#include "WinD3D.h"
#include "Buffer.h"
#include "Structures/Vertex.h"
#include "Graphics/Errors/BufferEmptyGraphicsError.h"

namespace GrainEngine::Graphics
{
	using namespace GrainEngine::Structures;
	using namespace GrainEngine::Errors;
	using namespace GrainEngine::Graphics::Errors;

	class VertexBuffer : public Buffer
	{
	public:
		VertexBuffer();
		~VertexBuffer() noexcept override = default;

		void Bind() override;

		void Create(const Vertex* pVertices, unsigned int numberOfVertices);

	private:
		UINT _stride = sizeof(Vertex);
		UINT _offset = 0u;
	};
}