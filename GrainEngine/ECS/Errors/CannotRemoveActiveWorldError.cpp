#include "CannotRemoveActiveWorldError.h"

namespace GrainEngine::ECS::Errors
{
	CannotRemoveActiveWorldError::CannotRemoveActiveWorldError(const std::string& message, const char* fileName, unsigned int lineNumber) :
		Error(message, fileName, lineNumber)
	{}
}