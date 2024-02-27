#pragma once

#include "WinD3D.h"
#include "PipelineComponent.h"
#include "Graphics/Errors/D3DGraphicsError.h"

namespace GrainEngine::Graphics
{
	using Microsoft::WRL::ComPtr;

	using namespace GrainEngine::Graphics::Errors;
	using namespace GrainEngine::Errors;

	class InputLayout : public PipelineComponent
	{
	public:
		InputLayout(const ComPtr<ID3DBlob>& pVertexShaderBinary);
		~InputLayout() noexcept override = default;

		void Bind() override;


	private:
		void Create(const ComPtr<ID3DBlob>& pVertexShaderBinary);

	private:
		ComPtr<ID3D11InputLayout> _pInputLayout;
	};
}