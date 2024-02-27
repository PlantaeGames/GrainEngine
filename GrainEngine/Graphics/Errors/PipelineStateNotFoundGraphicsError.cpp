#include "PipelineStateNotFoundGraphicsError.h"

namespace GrainEngine::Graphics::Errors
{
	PipelineStateNotFoundGraphicsError::PipelineStateNotFoundGraphicsError(const std::string& message, const std::string& fileName, unsigned int lineNumber) :
		GraphicsError(message, fileName, lineNumber)
	{}
}