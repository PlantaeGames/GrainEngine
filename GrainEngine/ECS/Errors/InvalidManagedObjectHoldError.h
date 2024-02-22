#pragma once

#include <string>

#include "Errors/Error.h"

namespace GrainEngine::ECS
{

#define GENERATE_INVALID_MANAGED_HOLD_ERROR(message) InvalidManagedObjectHoldError(message, __FILE__, __LINE__)
#define THROW_INVALID_MANAGED_HOLD_ERROR(message) throw GENERATE_MANAGED_NULL_REFERENCE_ERROR(message)

	using namespace Errors;

	class InvalidManagedObjectHoldError : public Error
	{
	public:
		InvalidManagedObjectHoldError(const std::string& message, const char* fileName, unsigned int lineNumber);
		~InvalidManagedObjectHoldError() noexcept = default;

		InvalidManagedObjectHoldError(const InvalidManagedObjectHoldError& otherInstance) = delete;
		InvalidManagedObjectHoldError(InvalidManagedObjectHoldError&& oldInstance) noexcept = delete;

		InvalidManagedObjectHoldError& operator= (const InvalidManagedObjectHoldError& otherInstance) = delete;
		InvalidManagedObjectHoldError& operator= (InvalidManagedObjectHoldError&& oldInstance) noexcept = delete;

	};
}