#pragma once

#include "WinD3D.h"
#include "PipelineComponent.h"

namespace GrainEngine::Graphics
{
	using Microsoft::WRL::ComPtr;

	class PrimitiveTopology : public PipelineComponent
	{
	public:
		PrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY topology);
		~PrimitiveTopology() noexcept override = default;

		void Bind(const ComPtr<ID3D11DeviceContext>& pDeviceContext) override;

		D3D11_PRIMITIVE_TOPOLOGY GetTopology() const noexcept
		{
			return _topology;
		}

	private:
		D3D11_PRIMITIVE_TOPOLOGY _topology;
	};
}