#include "EntityNotFoundError.h"

namespace GrainEngine::ECS::Errors
{
	EntityNotFoundError::EntityNotFoundError(const std::string& message, const char* fileName, unsigned int lineNumber) :
		Error(message, fileName, lineNumber)
	{}
}