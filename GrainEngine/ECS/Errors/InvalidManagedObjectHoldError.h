#pragma once

#include <string>

#include "Errors/Error.h"

namespace GrainEngine::ECS::Errors
{

#define GENERATE_INVALID_MANAGED_HOLD_ERROR(message) InvalidManagedObjectHoldError(message, __FILE__, __LINE__)
#define THROW_INVALID_MANAGED_HOLD_ERROR(message) THROW(GENERATE_MANAGED_NULL_REFERENCE_ERROR(message))

	class InvalidManagedObjectHoldError : public GrainEngine::Errors::Error
	{
	public:
		InvalidManagedObjectHoldError(const std::string& message, const std::string& fileName, unsigned int lineNumber);
		~InvalidManagedObjectHoldError() noexcept override = default;
	};
}