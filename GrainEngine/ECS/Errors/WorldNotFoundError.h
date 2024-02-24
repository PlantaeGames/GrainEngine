#pragma once

#include <string>

#include "Errors/Error.h"

namespace GrainEngine::ECS::Errors
{
#define GENERATE_WORLD_NOT_FOUND_ERROR(message) WorldNotFoundError(message, __FILE__, __LINE__)
#define THROW_WORLD_NOT_FOUND_ERROR(message) THROW(GENERATE_WORLD_NOT_FOUND_ERROR(message))

	class WorldNotFoundError : GrainEngine::Errors::Error
	{
	public:
		WorldNotFoundError(const std::string& message, const std::string& fileName, unsigned int lineNumber);
		~WorldNotFoundError() noexcept override = default;
	};
}