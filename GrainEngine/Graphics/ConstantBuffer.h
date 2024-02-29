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

		void Create(unsigned int slot, const char* pInitialData);
		void Update(char* pData);

	private:
		UINT _stride = sizeof(Vector3);
		UINT _offset = 0u;
		UINT _size = (_stride * 3u);
		ConstantBufferBindPosition _bindPos;
		UINT _slot = 0u;
	};
}