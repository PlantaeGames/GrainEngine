#pragma once

#include <string>
#include <memory>

#include "IPipelineComponent.h"
#include "Utilities/FileReader.h"
#include "Graphics/Errors/UnableToLoadShaderGraphicsError.h"

namespace GrainEngine::Graphics
{
#define UNABLE_TO_LOAD_SHADER_GRAPHICS_ERROR_MESSAGE "Unable to Load Shader."

	using namespace GrainEngine::Utilities;
	using namespace GrainEngine::Utilities::Errors;
	using namespace GrainEngine::Graphics::Errors;

	/// <summary>
	/// Base class for Shaders.
	/// </summary>
	class Shader : IPipelineComponent
	{
	public:
		Shader(const std::string& fileName);
		virtual ~Shader() noexcept override;

		virtual void Bind() override = 0;

	private:
		void LoadToPrimaryMemory();

	protected:
		virtual void LoadToGPUMemory() = 0;

	protected:
		std::string _fileName;
		std::unique_ptr<byte[]> _pBinary;
	};
}

