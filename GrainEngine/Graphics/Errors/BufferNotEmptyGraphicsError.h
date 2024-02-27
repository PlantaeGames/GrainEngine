#pragma once

#include <string>

#include "GraphicsError.h"

namespace GrainEngine::Graphics::Errors
{
#define GENERATE_BUFFER_NOT_EMPTY_GRAPHICS_ERROR(message) BufferNotEmptyGraphicsError(message, __FILE__, __LINE__)
#define THROW_BUFFER_NOT_EMPTY_GRAPHICS_ERROR(message) THROW(GENERATE_BUFFER_NOT_EMPTY_GRAPHICS_ERROR(message))

	class BufferNotEmptyGraphicsError : public GraphicsError
	{
	public:
		BufferNotEmptyGraphicsError(const std::string& message, const std::string& fileName, unsigned int lineNumber);
		~BufferNotEmptyGraphicsError() noexcept override = default;
	};
}