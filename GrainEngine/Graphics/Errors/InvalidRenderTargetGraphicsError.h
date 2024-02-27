#pragma once

#include <string>

#include "GraphicsError.h"

namespace GrainEngine::Graphics::Errors
{
#define GENERATE_INVALID_RENDER_TARGET_GRAPHICS_ERROR(message) InvalidRenderTargetGraphicsError(message, __FILE__, __LINE__)
#define THROW_INVALID_RENDER_TARGET_GRAPHICS_ERROR(message) THROW(GENERATE_INVALID_RENDER_TARGET_GRAPHICS_ERROR(message))

	class InvalidRenderTargetGraphicsError : public GraphicsError
	{
	public:
		InvalidRenderTargetGraphicsError(const std::string& message, const std::string& fileName, unsigned int lineNumber);
		~InvalidRenderTargetGraphicsError() noexcept override = default;
	};
}