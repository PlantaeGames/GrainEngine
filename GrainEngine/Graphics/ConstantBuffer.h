#pragma once

#include "WinD3D.h"
#include "Buffer.h"
#include "Structures/Vertex.h"
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
		void Update(const float** ppTransform);

	private:
		UINT _stride = sizeof(float);
		UINT _rows = 3u;
		UINT _columns = 3u;
		UINT _offset = 0u;
		ConstantBufferBindPosition _bindPos;
		UINT _slot = 0u;
	};
}