#pragma once

#include "WinD3D.h"
#include "PipelineComponent.h"
#include "Graphics/Errors/D3DGraphicsError.h"
#include "Graphics/Errors/InvalidRenderTargetGraphicsError.h"

namespace GrainEngine::Graphics
{
#define INVALID_RENDER_TARGET_GRAPHICS_ERROR_MESSAGE "Invalid Render Target."

	using Microsoft::WRL::ComPtr;

	using namespace GrainEngine::Errors;
	using namespace GrainEngine::Graphics::Errors;

	class RenderTargetView : public PipelineComponent
	{
	public:
		RenderTargetView() = default;
		RenderTargetView(const ComPtr<ID3D11Resource>& pBuffer);
		~RenderTargetView() noexcept override = default;

		void Bind() override;

		void Clear();

		void New(const ComPtr<ID3D11Resource>& pBuffer);
		void Release();

	private:
		bool CheckValid() const noexcept;

	private:
		ComPtr<ID3D11RenderTargetView> _pTargetView;
	};
}