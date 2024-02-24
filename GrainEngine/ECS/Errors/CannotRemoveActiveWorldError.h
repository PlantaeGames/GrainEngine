#pragma once

#include <string>

#include "Errors/Error.h"

namespace GrainEngine::ECS::Errors
{
#define GENERATE_CANNOT_REMOVE_ACTIVE_WORLD_ERROR(message) CannotRemoveActiveWorldError(message, __FILE__, __LINE__)
#define THROW_CANNOT_REMOVE_ACTIVE_WORLD_ERROR(message) THROW(GENERATE_CANNOT_REMOVE_ACTIVE_WORLD_ERROR(message))

	class CannotRemoveActiveWorldError : GrainEngine::Errors::Error
	{
	public:
		CannotRemoveActiveWorldError(const std::string& message, const std::string& fileName, unsigned int lineNumber);
		~CannotRemoveActiveWorldError() noexcept override = default;
	};
}
