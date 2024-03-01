#pragma once

#include <string>

#include "GraphicsError.h"

namespace GrainEngine::Graphics::Errors
{
#define GENERATE_INVALID_TEXTURE_GRAPHICS_ERROR(message) InvalidTextureGraphicsError(message, __FILE__, __LINE__)
#define THROW_INVALID_TEXTURE_GRAPHICS_ERROR(message) THROW(GENERATE_INVALID_TEXTURE_GRAPHICS_ERROR(message))

	class InvalidTextureGraphicsError : public GraphicsError
	{
	public:
		InvalidTextureGraphicsError(const std::string& message, const std::string& fileName, unsigned int lineNumber);
		~InvalidTextureGraphicsError() noexcept override = default;
	};
}