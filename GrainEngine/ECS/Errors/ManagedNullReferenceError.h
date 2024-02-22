#pragma once

#include <string>

#include "Errors/Error.h"

namespace GrainEngine::ECS
{
#define GENERATE_MANAGED_NULL_REFERENCE_ERROR(message) ManagedNullReferenceError(message, __FILE__, __LINE__)
#define THROW_MANAGED_NULL_REFERENCE_ERROR(message) throw GENERATE_MANAGED_NULL_REFERENCE_ERROR(message)

	using namespace Errors;

	class ManagedNullReferenceError : public Error
	{
	public:
		ManagedNullReferenceError(const std::string& message,  const char* fileName, unsigned int lineNumber);
		~ManagedNullReferenceError() noexcept = default;

		ManagedNullReferenceError(const ManagedNullReferenceError& otherInstance) = delete;
		ManagedNullReferenceError(ManagedNullReferenceError&& oldInstance) noexcept = delete;

		ManagedNullReferenceError& operator= (const ManagedNullReferenceError& otherInstance) = delete;
		ManagedNullReferenceError& operator= (ManagedNullReferenceError&& oldInstance) noexcept = delete;
	};
}
