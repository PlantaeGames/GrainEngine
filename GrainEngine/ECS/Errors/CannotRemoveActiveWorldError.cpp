#include "CannotRemoveActiveWorldError.h"

namespace GrainEngine::ECS::Errors
{
	CannotRemoveActiveWorldError::CannotRemoveActiveWorldError(const std::string& message, const std::string& fileName, unsigned int lineNumber) :
		Error(message, fileName, lineNumber)
	{}
}