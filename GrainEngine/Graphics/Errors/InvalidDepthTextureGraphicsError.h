#pragma once

#include <string>

#include "GraphicsError.h"

namespace GrainEngine::Graphics::Errors
{
#define GENERATE_INVALID_DEPTH_TEXTURE_GRAPHICS_ERROR(message) InvalidDepthTextureGraphicsError(message, __FILE__, __LINE__)
#define THROW_INVALID_DEPTH_TEXTURE_GRAPHICS_ERROR(message) THROW(GENERATE_INVALID_DEPTH_TEXTURE_GRAPHICS_ERROR(message))

	class InvalidDepthTextureGraphicsError : public GraphicsError
	{
	public:
		InvalidDepthTextureGraphicsError(const std::string& message, const std::string& fileName, unsigned int lineNumber);
		~InvalidDepthTextureGraphicsError() noexcept override = default;
	};
}