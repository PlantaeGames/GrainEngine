#include "EntityNotFoundError.h"

namespace GrainEngine::ECS::Errors
{
	EntityNotFoundError::EntityNotFoundError(const std::string& message, const std::string& fileName, unsigned int lineNumber) :
		Error(message, fileName, lineNumber)
	{}
}