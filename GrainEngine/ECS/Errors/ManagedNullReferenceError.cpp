#include "ManagedNullReferenceError.h"

namespace GrainEngine::ECS::Errors
{
	ManagedNullReferenceError::ManagedNullReferenceError(const std::string& message, const std::string& fileName, unsigned int lineNumber) :
		Error(message, fileName, lineNumber)
	{}
}