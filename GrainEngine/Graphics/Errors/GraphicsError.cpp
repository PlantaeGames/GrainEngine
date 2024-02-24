#include "GraphicsError.h"

namespace GrainEngine::Graphics::Errors
{
	GraphicsError::GraphicsError(const std::string& message, const std::string& fileName, unsigned int lineNumber) :
		Error(message, fileName, lineNumber)
	{}
}