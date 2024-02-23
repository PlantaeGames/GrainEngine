#include "InputDeviceNotFoundError.h"

namespace GrainEngine::Input::Errors
{
	InputDeviceNotFoundError::InputDeviceNotFoundError(const std::string& message, const char* fileName, unsigned int lineNumber) :
		Error(message, fileName, lineNumber)
	{}
}