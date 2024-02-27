#pragma once

#include <string>

#include "GraphicsError.h"

namespace GrainEngine::Graphics::Errors
{
#define GENERATE_BUFFER_EMPTY_GRAPHICS_ERROR(message) BufferEmptyGraphicsError(message, __FILE__, __LINE__)
#define THROW_BUFFER_EMPTY_GRAPHICS_ERROR(message) THROW(GENERATE_BUFFER_EMPTY_GRAPHICS_ERROR(message))

	class BufferEmptyGraphicsError : public GraphicsError
	{
	public:
		BufferEmptyGraphicsError(const std::string& message, const std::string& fileName, unsigned int lineNumber);
		~BufferEmptyGraphicsError() noexcept override = default;
	};
}