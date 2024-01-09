#include "DebugConsole.h"
#include "Error.h"

namespace GrainEngine::Errors
{
	DebugConsole::DebugConsole():
		Singleton()
	{
		CreateConsoleWindow();
	}

	DebugConsole::~DebugConsole()
	{
		FreeConsole();
	}

	void DebugConsole::CreateConsoleWindow()
	{
		if (AllocConsole() == false)
		{
			// error
			THROW_ERROR(CREATE_DEBUG_CONSOLE_ERROR);
		}

		_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	void DebugConsole::Print(const std::string& message) const
	{
		bool result = false;

		unsigned int temp = 0;
		result = WriteConsoleA(_handle, message.c_str(), (DWORD) message.length(), (LPDWORD) & temp, 0);

		if (result == false)
		{
			THROW_ERROR(WRITE_CONSOLE_ERROR);
		}
	}

	void DebugConsole::ResetCursor() const noexcept
	{
		SetConsoleCursorPosition(_handle, {0, 0});
	}
}