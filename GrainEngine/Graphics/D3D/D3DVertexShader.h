#pragma once

#include <string>

#include "WinD3D.h"
#include "D3DShader.h"
#include "Graphics/D3D/Errors/D3DGraphicsError.h"

namespace GrainEngine::Graphics::D3D
{
	using Microsoft::WRL::ComPtr;

	using namespace GrainEngine::Errors;
	using namespace GrainEngine::Graphics::D3D::Errors;

	/// <summary>
	/// DirectX 11 Vertex Shader loaded on GPU.
	/// </summary>
	class D3DVertexShader : public D3DShader
	{
	public:
		D3DVertexShader(const std::string& fileName, const ComPtr<ID3D11Device>& pDevice,
			const ComPtr<ID3D11DeviceContext>& pDeviceContext);
		~D3DVertexShader() noexcept override = default;

		void Bind() override;

	private:
		/// <summary>
		/// Loads the Shader on GPU.
		/// </summary>
		void Load();

	private:
		ComPtr<ID3D11VertexShader> _pVertexShader;
		ComPtr<ID3D11Device> _pDevice;
		ComPtr<ID3D11DeviceContext> _pDeviceContext;
	};
}