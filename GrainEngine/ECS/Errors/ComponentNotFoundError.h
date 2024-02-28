#pragma once

#include <string>

#include "Errors/Error.h"

namespace GrainEngine::ECS::Errors
{
#define GENERATE_COMPONENT_NOT_FOUND_ERROR(message) ComponentNotFoundError(message, __FILE__, __LINE__)
#define THROW_COMPONENT_NOT_FOUND_ERROR(message) THROW(GENERATE_COMPONENT_NOT_FOUND_ERROR(message))

	class ComponentNotFoundError : public GrainEngine::Errors::Error
	{
	public:
		ComponentNotFoundError(const std::string& message, const std::string& fileName, unsigned int lineNumber);
		~ComponentNotFoundError() noexcept override = default;
	};
}