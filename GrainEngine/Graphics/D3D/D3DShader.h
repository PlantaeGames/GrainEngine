#pragma once

#include <string>
#include <memory>
#include <sstream>
#include <string>

#include "WinD3D.h"
#include "Graphics/Shader.h"
#include "Graphics/D3D/Errors/D3DGraphicsError.h"

namespace GrainEngine::Graphics::D3D
{
	using Microsoft::WRL::ComPtr;

	using namespace GrainEngine::Errors;
	using namespace GrainEngine::Graphics::D3D::Errors;

	/// <summary>
	/// Direct X 11 Shader, implenenting base Shader class and is a IPipelineComponent.
	/// </summary>
	class D3DShader : public Shader
	{
	public:
		D3DShader(const std::string& fileName);
		virtual ~D3DShader() noexcept override = default;

		virtual void Bind() override;

	private:
		void Load();

		void LoadToPrimaryMemory() override;
		void LoadToGPUMemory() override;

	protected:
		std::wstring _wFileName;
		ComPtr<ID3DBlob> _pBinary;
	};
}