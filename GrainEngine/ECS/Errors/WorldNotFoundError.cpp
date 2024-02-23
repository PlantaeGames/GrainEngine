#include "WorldNotFoundError.h"

namespace GrainEngine::ECS::Errors
{
	WorldNotFoundError::WorldNotFoundError(const std::string& message, const char* fileName, unsigned int lineNumber) :
		Error(message, fileName, lineNumber)
	{}
}