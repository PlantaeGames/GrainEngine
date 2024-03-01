#pragma once

#include <string>

#include "GraphicsError.h"

namespace GrainEngine::Graphics::Errors
{
#define GENERATE_INVALID_DEPTH_VIEW_GRAPHICS_ERROR(message) InvalidDepthViewGraphicsError(message, __FILE__, __LINE__)
#define THROW_INVALID_DEPTH_VIEW_GRAPHICS_ERROR(message) THROW(GENERATE_INVALID_DEPTH_VIEW_GRAPHICS_ERROR(message))

	class InvalidDepthViewGraphicsError : public GraphicsError
	{
	public:
		InvalidDepthViewGraphicsError(const std::string& message, const std::string& fileName, unsigned int lineNumber);
		~InvalidDepthViewGraphicsError() noexcept override = default;
	};
}