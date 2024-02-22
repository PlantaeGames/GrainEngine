#pragma once

#include <string>

#include "Errors/Error.h"

namespace GrainEngine::ECS
{
#define GENERATE_COMPONENT_NOT_FOUND_ERROR(message) ComponentNotFoundError(message, __FILE__, __LINE__)
#define THROW_COMPONENT_NOT_FOUND_ERROR(message) GENERATE_COMPONENT_NOT_FOUND_ERROR(message)

	using namespace Errors;

	class ComponentNotFoundError : public Error
	{
		ComponentNotFoundError(const std::string& message, const char* fileName, unsigned int lineNumber);
		~ComponentNotFoundError() noexcept override = default;

		ComponentNotFoundError(const ComponentNotFoundError& otherInstance) = delete;
		ComponentNotFoundError(ComponentNotFoundError&& oldInstance) noexcept = delete;

		ComponentNotFoundError& operator= (const ComponentNotFoundError& otherInstance) = delete;
		ComponentNotFoundError& operator= (ComponentNotFoundError&& oldInstance) noexcept = delete;
	};
}