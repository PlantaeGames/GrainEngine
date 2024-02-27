#pragma once

#include "WinD3D.h"

namespace GrainEngine::Graphics
{
	using Microsoft::WRL::ComPtr;

	class PipelineComponent
	{
	public:
		PipelineComponent(const ComPtr<ID3D11Device>& pDevice);
		virtual ~PipelineComponent() noexcept = default;

		virtual void Bind(const ComPtr<ID3D11DeviceContext>& pDeviceContext) = 0;

	protected:
		ComPtr<ID3D11Device> _pDevice;
	};
}
