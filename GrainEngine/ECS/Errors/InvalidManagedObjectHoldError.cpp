#include "InvalidManagedObjectHoldError.h"

namespace GrainEngine::ECS
{
	InvalidManagedObjectHoldError::InvalidManagedObjectHoldError(const std::string& message, const char* fileName, unsigned int lineNumber) :
		Error(message, fileName, lineNumber)
	{}
}