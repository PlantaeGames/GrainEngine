#include "InputDeviceNotFoundError.h"

namespace GrainEngine::Input::Errors
{
	InputDeviceNotFoundError::InputDeviceNotFoundError(const std::string& message, const std::string& fileName, unsigned int lineNumber) :
		Error(message, fileName, lineNumber)
	{}
}