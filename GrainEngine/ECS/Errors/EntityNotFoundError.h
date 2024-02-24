#pragma once

#include <string>

#include "Errors/Error.h"

namespace GrainEngine::ECS::Errors
{
#define GENERATE_ENTITY_NOT_FOUND_ERROR(message) EntityNotFoundError(message, __FILE__, __LINE__)
#define THROW_ENTITY_NOT_FOUND_ERROR(message) THROW(GENERATE_ENTITY_NOT_FOUND_ERROR(message))

	class EntityNotFoundError : public GrainEngine::Errors::Error
	{
	public:
		EntityNotFoundError(const std::string& message, const std::string& fileName, unsigned int lineNumber);
		~EntityNotFoundError() noexcept override = default;
	};
}