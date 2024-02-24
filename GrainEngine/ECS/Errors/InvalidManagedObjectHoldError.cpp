#include "InvalidManagedObjectHoldError.h"

namespace GrainEngine::ECS::Errors
{
	InvalidManagedObjectHoldError::InvalidManagedObjectHoldError(const std::string& message, const std::string& fileName, unsigned int lineNumber) :
		Error(message, fileName, lineNumber)
	{}
}