#include "BufferNotEmptyGraphicsError.h"

namespace GrainEngine::Graphics::Errors
{
	BufferNotEmptyGraphicsError::BufferNotEmptyGraphicsError(const std::string& message, const std::string& fileName, unsigned int lineNumber) :
		GraphicsError(message, fileName, lineNumber)
	{}
}