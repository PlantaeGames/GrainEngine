#pragma once

#include <string>

#include "Errors/Error.h"

namespace GrainEngine::ECS::Errors
{
#define GENERATE_MANAGED_NULL_REFERENCE_ERROR(message) ManagedNullReferenceError(message, __FILE__, __LINE__)
#define THROW_MANAGED_NULL_REFERENCE_ERROR(message) THROW(GENERATE_MANAGED_NULL_REFERENCE_ERROR(message))

	class ManagedNullReferenceError : public GrainEngine::Errors::Error
	{
	public:
		ManagedNullReferenceError(const std::string& message,  const std::string& fileName, unsigned int lineNumber);
		~ManagedNullReferenceError() noexcept override = default;
	};
}
