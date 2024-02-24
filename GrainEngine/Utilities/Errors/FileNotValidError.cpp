#include "FileNotValidError.h"

namespace GrainEngine::Utilities::Errors
{
	FileNotValidError::FileNotValidError(const std::string& message, const std::string& fileName, unsigned int lineNumber) :
		Error(message, fileName, lineNumber)
	{}
}