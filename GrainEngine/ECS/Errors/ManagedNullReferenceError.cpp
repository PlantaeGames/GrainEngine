#include "ManagedNullReferenceError.h"

namespace GrainEngine::ECS::Errors
{
	ManagedNullReferenceError::ManagedNullReferenceError(const std::string& message, const char* fileName, unsigned int lineNumber) :
		Error(message, fileName, lineNumber)
	{}
}