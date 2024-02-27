#pragma once

#include <string>
#include <memory>
#include <sstream>

#include "WinD3D.h"
#include "PipelineComponent.h"
#include "Errors/Error.h"
#include "Graphics/Errors/D3DGraphicsError.h"

namespace GrainEngine::Graphics
{
	using namespace GrainEngine::Errors;
	using namespace GrainEngine::Graphics::Errors;

	/// <summary>
	/// Base class for Shaders.
	/// </summary>
	class Shader : public PipelineComponent
	{
	public:
		Shader(const std::string& fileName);
		virtual ~Shader() noexcept override = default;

		virtual void Bind(const ComPtr<ID3D11DeviceContext>& pDeviceContext) override = 0;

	private:
		void LoadToCPU();

	protected:
		std::wstring _wFileName;
		ComPtr<ID3DBlob> _pBinary;
	};
}

