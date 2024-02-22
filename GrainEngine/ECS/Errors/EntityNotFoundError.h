#pragma once

#include <string>

#include "Errors/Error.h"

namespace GrainEngine::ECS
{
#define GENERATE_ENTITY_NOT_FOUND_ERROR(message) EntityNotFoundError(message, __FILE__, __LINE__)
#define THROW_ENTITY_NOT_FOUND_ERROR(message) throw GENERATE_ENTITY_NOT_FOUND_ERROR(message)

	using namespace Errors;

	class EntityNotFoundError : public Error
	{
	public:
		EntityNotFoundError(const std::string& message, const char* fileName, unsigned int lineNumber);
		~EntityNotFoundError() noexcept override = default;

		EntityNotFoundError(const EntityNotFoundError& otherInstance) = delete;
		EntityNotFoundError(EntityNotFoundError&& oldInstance) noexcept = delete;

		EntityNotFoundError& operator= (const EntityNotFoundError& otherInstance) = delete;
		EntityNotFoundError& operator= (EntityNotFoundError&& oldInstance) noexcept = delete;
	};
}