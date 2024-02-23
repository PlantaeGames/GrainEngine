#pragma once

#include <string>

#include "Errors/Error.h"

namespace GrainEngine::ECS::Errors
{
#define GENERATE_CANNOT_REMOVE_ACTIVE_WORLD_ERROR(message) CannotRemoveActiveWorldError(message, __FILE__, __LINE__)
#define THROW_CANNOT_REMOVE_ACTIVE_WORLD_ERROR(message) throw GENERATE_CANNOT_REMOVE_ACTIVE_WORLD_ERROR(message)

	class CannotRemoveActiveWorldError : GrainEngine::Errors::Error
	{
	public:
		CannotRemoveActiveWorldError(const std::string& message, const char* fileName, unsigned int lineNumber);
		~CannotRemoveActiveWorldError() noexcept override = default;

		CannotRemoveActiveWorldError(const CannotRemoveActiveWorldError& otherInstance) = delete;
		CannotRemoveActiveWorldError(CannotRemoveActiveWorldError&& oldInstance) noexcept = delete;

		CannotRemoveActiveWorldError& operator= (const CannotRemoveActiveWorldError& otherInstance) = delete;
		CannotRemoveActiveWorldError& operator= (CannotRemoveActiveWorldError&& oldInstance) noexcept = delete;
	};
}
