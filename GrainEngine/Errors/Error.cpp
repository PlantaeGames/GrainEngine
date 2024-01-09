#include "Error.h"

namespace GrainEngine::Errors
{
	Error::Error(const char* message, const char* fileName, unsigned int lineNumber) :
		std::runtime_error(message)
	{
		assert(strlen(message) > 0);

		unsigned int lengthOfFileName = (unsigned int)strlen(fileName);
		assert(lengthOfFileName > 0);

		char* tempFileName = new char[lengthOfFileName + 1];
		if (tempFileName == nullptr)
		{
			// error
			throw runtime_error(MEMORY_ALLOCATION_ERROR);
		}

		errno_t result = 0;
		result = strcpy_s(tempFileName, lengthOfFileName + 1, fileName);

		if (result != 0)
		{
			// error
			throw runtime_error(MEMORY_COPY_ERROR);
		}
		_fileName = tempFileName;

		_lineNumber = lineNumber;
	}

	std::string Error::What() const noexcept
	{
		std::stringstream message;
		message << "[RUNTIME ERROR]\n\n";
		message << "[FileName]\n\t";
		message << _fileName;
		message << "\n";
		message << "Line Number: ";
		message << _lineNumber;
		message << "\n\n";
		message << "[Details]\n";
		message << runtime_error::what();

		return message.str();
	}

	void Error::Show() const noexcept
	{
		MessageBoxExA(nullptr, What().c_str(), "ERROR", MB_ICONERROR, 0);
	}

	Error::~Error() noexcept
	{
		delete _fileName;
	}

	void Error::Log(const std::string& message) noexcept
	{
#ifdef _DEBUG
		DebugConsole::GetInstance().Print(message);
#endif // _DEBUG
	}
}