#pragma once

#include <string>

#include "GraphicsError.h"

namespace GrainEngine::Graphics::Errors
{
#define GENERATE_UNABLE_TO_LOAD_SHADER_GRAPHICS_ERROR(message) UnableToLoadShaderGraphicsError(message, __FILE__, __LINE__)
#define THROW_UNABLE_TO_LOAD_SHADER_GRAPHICS_ERROR(message) THROW(GENERATE_UNABLE_TO_LOAD_SHADER_GRAPHICS_ERROR(message))

	class UnableToLoadShaderGraphicsError : public GraphicsError
	{
	public:
		UnableToLoadShaderGraphicsError(const std::string& message, const std::string& fileName, unsigned int lineNumber);
		~UnableToLoadShaderGraphicsError() noexcept override = default;
	};
}
