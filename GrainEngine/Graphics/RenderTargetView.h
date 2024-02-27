#pragma once

#include "WinD3D.h"
#include "PipelineComponent.h"
#include "Graphics/Errors/D3DGraphicsError.h"

namespace GrainEngine::Graphics
{
	using Microsoft::WRL::ComPtr;

	using namespace GrainEngine::Errors;
	using namespace GrainEngine::Graphics::Errors;

	class RenderTargetView : public PipelineComponent
	{
	public:
		RenderTargetView(const ComPtr<ID3D11Resource>& pBuffer);
		~RenderTargetView() noexcept override = default;

		void Bind() override;

		void Clear(const ComPtr<ID3D11DeviceContext>& pDeviceContext);

	private:
		void Create(const ComPtr<ID3D11Resource>& pBuffer);

	private:
		ComPtr<ID3D11RenderTargetView> _pTargetView;
	};
}