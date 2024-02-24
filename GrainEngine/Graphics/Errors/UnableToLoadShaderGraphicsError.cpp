#include "UnableToLoadShaderGraphicsError.h"

namespace GrainEngine::Graphics::Errors
{
	UnableToLoadShaderGraphicsError::UnableToLoadShaderGraphicsError(const std::string& message, const std::string& fileName, unsigned int lineNumber) :
		GraphicsError(message, fileName, lineNumber)
	{}
}