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

	class IndexBuffer : public Buffer
	{
	public:
		IndexBuffer() = default;
		~IndexBuffer() noexcept override = default;

		void Bind() override;

		void Create(const unsigned int* pIndices, unsigned int indicesCount);

	private:
		UINT _stride = sizeof(unsigned int);
		UINT _offset = 0u;
	};
}