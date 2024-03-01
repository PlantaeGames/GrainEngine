#pragma once

#include "WinD3D.h"
#include "PipelineComponent.h"
#include "Graphics/Errors/D3DGraphicsError.h"
#include "Graphics/Errors/InvalidDepthViewGraphicsError.h"

namespace GrainEngine::Graphics
{
#define INVALID_DEPTH_VIEW_GRAPHICS_ERROR_MESSAGE "Invalid Depth View."

	using Microsoft::WRL::ComPtr;

	using namespace GrainEngine::Graphics::Errors;
	using namespace GrainEngine::Errors;

	class DepthView : public PipelineComponent
	{
	public:
		DepthView() = default;
		DepthView(const ComPtr<ID3D11Texture2D>& pDepthTexture);

		~DepthView() noexcept override = default;

		void Bind() override;

		void Create(const ComPtr<ID3D11Texture2D>& pDepthTexture);
		void Release();

		ComPtr<ID3D11DepthStencilView> GetView() const noexcept
		{
			return _pDepthView;
		}

	private:
		void New(const ComPtr<ID3D11Texture2D>& pDepthTexture);
		bool CheckValid() const noexcept;

	private:
		ComPtr<ID3D11DepthStencilView> _pDepthView;
		bool _valid = false;
	};
}