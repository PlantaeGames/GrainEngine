#include "ComponentNotFoundError.h"

namespace GrainEngine::ECS
{
	ComponentNotFoundError::ComponentNotFoundError(const std::string& message, const char* fileName, unsigned int lineNumber) :
		Error(message, fileName, lineNumber)
	{}
}