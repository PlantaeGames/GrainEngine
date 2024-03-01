#pragma once

#include "WinD3D.h"
#include "PipelineComponent.h"
#include "Graphics\Errors\GraphicsError.h"

namespace GrainEngine::Graphics
{
	using Microsoft::WRL::ComPtr;

	using namespace GrainEngine::Errors;
	using namespace GrainEngine::Graphics::Errors;

	class DepthState : public PipelineComponent
	{
	public:
		DepthState();
		~DepthState() noexcept override = default;

		void Bind() override;

	private:
		void Create();

	private:
		ComPtr<ID3D11DepthStencilState> _pDepthState;
	};
}