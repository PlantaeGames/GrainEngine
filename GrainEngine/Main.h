#pragma once

#include <Windows.h>

#include "Components/MainWindow.h"
#include "Components/InputManager.h"
#include "Diagnostics/Stopwatch.h"
#include "Components/InputManager.h"
#include "Errors/Error.h"

namespace GrainEngine
{
#define WINDOW_NAME L"GrainEngine"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

	using namespace Components;
	using namespace Input;
	using namespace Diagnostics;
	using namespace Errors;

	/// <summary>
	/// The Main function of the engine.
	/// </summary>
	/// <returns>Exit Code.</returns>
	size_t Main();
}

/// <summary>
/// Entry Point of the program.
/// </summary>
/// <param name="hInstance">Handle to the program in memory.</param>
/// <param name="hPrevInstance">Obsolete.</param>
/// <param name="lpCmdLine">Pointer to command line argumanets.</param>
/// <param name="nShowCmd">Requested State of window.</param>
/// <returns></returns>
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	using namespace GrainEngine;
	using namespace Errors;

	size_t returnCode = 0;
	try
	{
		// starting engine.
		returnCode = Main();
	}
	catch (const Error& error)
	{
		error.Show();
	}
	catch (const std::exception& exception)
	{
		GENERATE_ERROR(exception.what()).Show();
	}
	return (int)returnCode;
}