#pragma once

#include <string>

#include "Errors/Error.h"

namespace GrainEngine::Graphics::Errors
{
#define GENERATE_GRAPHICS_ERROR(message) GraphicsError(message, __FILE__, __LINE__)
#define THROW_GRAPHICS_ERROR(message) THROW(GENERATE_GRAPHICS_ERROR(message))

	class GraphicsError : public GrainEngine::Errors::Error
	{
	public:
		GraphicsError(const std::string& message, const std::string& fileName, unsigned int lineNumber);
		virtual ~GraphicsError() noexcept override = default;
	};
}