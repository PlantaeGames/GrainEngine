#pragma once

#include "WinD3D.h"
#include "Buffer.h"
#include "Structures/Vertex.h"
#include "Structures/Vector3.h"
#include "ConstantBufferBindPosition.h"
#include "Graphics/Errors/BufferEmptyGraphicsError.h"

namespace GrainEngine::Graphics
{
	using namespace GrainEngine::Structures;
	using namespace GrainEngine::Errors;
	using namespace GrainEngine::Graphics::Errors;

	class VertexBuffer;

	class ConstantBuffer : public Buffer
	{
	public:
		ConstantBuffer(ConstantBufferBindPosition bindPos);
		~ConstantBuffer() noexcept override = default;

		void Bind() override;

		void Create(unsigned int slot, unsigned int size, unsigned int stride, const char* pInitialData);
		void Update(char* pData);

	private:
		UINT _stride = 0u;
		UINT _offset = 0u;
		ConstantBufferBindPosition _bindPos;
		UINT _slot = 0u;
	};
}