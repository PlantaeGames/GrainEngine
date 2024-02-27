#pragma once

#include "WinD3D.h"
#include "Device.h"

namespace GrainEngine::Graphics
{
	using Microsoft::WRL::ComPtr;

	class PipelineComponent
	{
	public:
		PipelineComponent();
		virtual ~PipelineComponent() noexcept = default;

		virtual void Bind(const ComPtr<ID3D11DeviceContext>& pDeviceContext) = 0;

	protected:
		ComPtr<ID3D11Device> _pDevice;
	};
}
