#include "Shader.h"

namespace GrainEngine::Graphics
{
	void Shader::LoadToPrimaryMemory()
	{
		try
		{
			FileReader fileReader = { _fileName };
			_pBinary = std::make_unique<byte[]>(fileReader.GetSize());

			fileReader.ReadAll(_pBinary);
		}
		catch(const FileNotValidError& error)
		{
			auto shaderError = GENERATE_UNABLE_TO_LOAD_SHADER_GRAPHICS_ERROR(UNABLE_TO_LOAD_SHADER_GRAPHICS_ERROR_MESSAGE);
			shaderError.Append(error.What());

			THROW(shaderError);
		}
	}

	Shader::Shader(const std::string& fileName) :
		_fileName(fileName),
		_pBinary(nullptr)
	{
		LoadToPrimaryMemory();
	}

	Shader::~Shader() noexcept
	{}
}