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

	void DebugConsole::CLS() const noexcept
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		SMALL_RECT scrollRect;
		COORD scrollTarget;
		CHAR_INFO fill;

		// Get the number of character cells in the current buffer.
		if (!GetConsoleScreenBufferInfo(_handle, &csbi))
		{
			return;
		}

		// Scroll the rectangle of the entire buffer.
		scrollRect.Left = 0;
		scrollRect.Top = 0;
		scrollRect.Right = csbi.dwSize.X;
		scrollRect.Bottom = csbi.dwSize.Y;

		// Scroll it upwards off the top of the buffer with a magnitude of the entire height.
		scrollTarget.X = 0;
		scrollTarget.Y = (SHORT)(0 - csbi.dwSize.Y);

		// Fill with empty spaces with the buffer's default text attribute.
		fill.Char.UnicodeChar = TEXT(' ');
		fill.Attributes = csbi.wAttributes;

		// Do the scroll
		ScrollConsoleScreenBuffer(_handle, &scrollRect, NULL, scrollTarget, &fill);

		// Move the cursor to the top left corner too.
		csbi.dwCursorPosition.X = 0;
		csbi.dwCursorPosition.Y = 0;

		SetConsoleCursorPosition(_handle, csbi.dwCursorPosition);
	}

	void DebugConsole::ResetCursor() const noexcept
	{
		SetConsoleCursorPosition(_handle, {0, 0});
	}

	void DebugConsole::Clear() const noexcept
	{
		CLS();
	}
}