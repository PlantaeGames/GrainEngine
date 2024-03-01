#include "InvalidDepthTextureGraphicsError.h"

namespace GrainEngine::Graphics::Errors
{
	InvalidDepthTextureGraphicsError::InvalidDepthTextureGraphicsError(const std::string& message, const std::string& fileName, unsigned int lineNumber) :
		GraphicsError(message, fileName, lineNumber)
	{}
}