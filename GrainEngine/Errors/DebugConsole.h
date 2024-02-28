#pragma once

#include <string>

#include <windows.h>

#include "Patterns/Singleton.h"

namespace GrainEngine::Errors
{
#define CREATE_DEBUG_CONSOLE_ERROR "Failed to create debug consolel."
#define WRITE_CONSOLE_ERROR "Failed in writing to console."

	using namespace Patterns;

	class DebugConsole : public Singleton<DebugConsole>
	{
		friend Singleton;
	public:
		DebugConsole(const DebugConsole& otherInstance) = delete;
		DebugConsole(DebugConsole&& oldInstance) noexcept = delete;
		DebugConsole& operator= (const DebugConsole& otherInstance) = delete;
		DebugConsole& operator= (DebugConsole&& oldInstance) noexcept = delete;

		~DebugConsole() noexcept;

		void Print(const std::string& message) const;
		void ResetCursor() const noexcept;
		void Clear() const noexcept;
	private:
		void CLS() const noexcept;
		DebugConsole();

		void CreateConsoleWindow();
	private:
		HANDLE _handle = nullptr;
	};
}