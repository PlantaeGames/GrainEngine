#pragma once

#include <stdexcept>
#include <windows.h>

#define MEMORY_ALLOCATION_ERROR "Failed to allocate memory."
#define MEMORY_COPY_ERROR "Failed to copy memory."

/// <summary>
/// Error showing pop up.
/// </summary>
class Error : std::runtime_error
{
public:
	/// <summary>
	/// Default Contructor.
	/// </summary>
	/// <param name="message">The message to show on pop up.</param>
	Error(const char* message);
	/// <summary>
	/// Show the error pop up.
	/// </summary>
	void ShowNotification() const;
	/// <summary>
	/// Gets the stored error message.
	/// </summary>
	/// <returns>Error message.</returns>
	const char* What() const noexcept;
};

