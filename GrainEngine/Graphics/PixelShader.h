#pragma once

#include <string>

#include "WinD3D.h"
#include "Shader.h"
#include "Graphics/Errors/D3DGraphicsError.h"

namespace GrainEngine::Graphics
{
	using Microsoft::WRL::ComPtr;

	using namespace GrainEngine::Errors;
	using namespace GrainEngine::Graphics::Errors;

	/// <summary>
	/// DirectX 11 Vertex Shader loaded on GPU.
	/// </summary>
	class PixelShader : public Shader
	{
	public:
		PixelShader(const std::string& fileName, const ComPtr<ID3D11Device>& pDevice);
		~PixelShader() noexcept override = default;

		/// <summary>
		/// Binds the shader to the pipeline.
		/// </summary>
		void Bind(const ComPtr<ID3D11DeviceContext>& pDeviceContext) override;

	private:
		/// <summary>
		/// Loads the Shader on GPU.
		/// </summary>
		void LoadToGPU();

	private:
		ComPtr<ID3D11PixelShader> _pPixelShader;
	};
}