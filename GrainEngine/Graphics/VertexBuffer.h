#pragma once

#include "WinD3D.h"
#include "Buffer.h"

namespace GrainEngine::Graphics
{
	class VertexBuffer : public Buffer
	{
	public:
		VertexBuffer(const ComPtr<ID3D11Device>& pDevice);
		~VertexBuffer() noexcept override = default;

		void Bind(const ComPtr<ID3D11DeviceContext>& pDeviceContext) override;
	};
}