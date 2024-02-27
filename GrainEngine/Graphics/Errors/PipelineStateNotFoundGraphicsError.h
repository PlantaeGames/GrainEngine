#pragma once

#include <string>

#include "GraphicsError.h"

namespace GrainEngine::Graphics::Errors
{
#define GENERATE_PIPELINE_STATE_NOT_FOUND_GRAPHICS_ERROR(message) PipelineStateNotFoundGraphicsError(message, __FILE__, __LINE__)
#define THROW_PIPELINE_STATE_NOT_FOUND_GRAPHICS_ERROR(message) THROW(GENERATE_PIPELINE_STATE_NOT_FOUND_GRAPHICS_ERROR(message))

	class PipelineStateNotFoundGraphicsError : public GraphicsError
	{
	public:
		PipelineStateNotFoundGraphicsError(const std::string& message, const std::string& fileName, unsigned int lineNumber);
		~PipelineStateNotFoundGraphicsError() noexcept override = default;
	};
}