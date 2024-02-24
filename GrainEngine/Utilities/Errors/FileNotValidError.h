#pragma once

#include <string>

#include "Errors/Error.h"

namespace GrainEngine::Utilities::Errors
{
#define GENERATE_FILE_NOT_VALID_ERROR(message) FileNotValidError(message, __FILE__, __LINE__)
#define THROW_FILE_NOT_VALID_ERROR(message) THROW(GENERATE_FILE_NOT_VALID_ERROR(message))

	class FileNotValidError : public GrainEngine::Errors::Error
	{
	public:
		FileNotValidError(const std::string& message, const std::string& fileName, unsigned int lineNumber);
		~FileNotValidError() noexcept override = default;
	};
}