#include "Shader.h"

namespace GrainEngine::Graphics
{
	void Shader::LoadToPrimaryMemory()
	{
		try
		{
			FileReader fileReader = { _fileName };
			_pCode = std::make_unique<byte[]>(fileReader.GetSize());

			fileReader.ReadAll(_pCode);
		}
		catch(const FileNotValidError& error)
		{
			auto shaderError = GENERATE_UNABLE_TO_LOAD_SHADER_GRAPHICS_ERROR(UNABLE_TO_LOAD_SHADER_GRAPHICS_ERROR_MESSAGE);
			shaderError.Append(error.What());

			THROW(shaderError);
		}
	}

	void Shader::LoadToGPUMemory() 
	{}

	Shader::Shader(const std::string& fileName) :
		_fileName(),
		_pCode(nullptr)
	{
		assert(_fileName.length() > 0);

		_fileName = fileName;

		LoadToPrimaryMemory();
		LoadToGPUMemory();
	}

	Shader::~Shader() noexcept
	{}
}