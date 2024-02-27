#include "BufferEmptyGraphicsError.h"

namespace GrainEngine::Graphics::Errors
{
	BufferEmptyGraphicsError::BufferEmptyGraphicsError(const std::string& message, const std::string& fileName, unsigned int lineNumber) :
		GraphicsError(message, fileName, lineNumber)
	{}
}