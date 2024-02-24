#include "Error.h"

namespace GrainEngine::Errors
{
	Error::Error(const std::string& message, const std::string& fileName, unsigned int lineNumber) :
		_lineNumber(lineNumber),
		_fileName(fileName),
		std::runtime_error(message),
		_information()
	{
		assert(message.length() > 0);
	}

	std::string Error::What() const noexcept
	{
		std::stringstream message;
		message << "[ RUNTIME ERROR ]\n\n";
		message << "[ FileName ]\t";
		message << _fileName;
		message << "\n";
		message << "Line Number: ";
		message << _lineNumber;
		message << "\n\n";
		message << "[ Details ]\n";
		message << runtime_error::what();

		message << "[ Extra Information ]\n";
		for (const auto& info : _information)
		{
			message << info;
		}

		return message.str();
	}

	void Error::Append(const std::string& message) noexcept
	{
		assert(message.length() > 0);

		_information.push_back(message + "\n");
	}

	void Error::Show() const noexcept
	{
		MessageBoxExA(nullptr, What().c_str(), "ERROR", MB_ICONERROR, 0);
	}

	void Error::Log(const std::string& message) noexcept
	{
#ifdef _DEBUG
		DebugConsole::GetInstance().Print(message);
#endif // _DEBUG
	}

	void Error::ResetLogCursor() noexcept
	{
#ifdef _DEBUG
		DebugConsole::GetInstance().ResetCursor();
#endif // _DEBUG
	}
}