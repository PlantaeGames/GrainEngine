#pragma once

#include <Windows.h>

#include "Components/Engine.h"
#include "Errors/Error.h"

namespace GrainEngine
{
	using namespace Components;
	using namespace Errors;

	/// <summary>
	/// The Main function of the engine.
	/// </summary>
	/// <returns>Exit Code.</returns>
	int Main();
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

	int returnCode = 0;
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
	catch (...)
	{
		Error::Log("Some UnExpected Happened.");
	}
	return returnCode;
}