#pragma once

#include <stdexcept>
#include <assert.h>
#include <sstream>
#include <string>

#include <windows.h>

#include "DebugConsole.h"

namespace GrainEngine::Errors
{
#define MEMORY_ALLOCATION_ERROR "Failed to allocate memory."
#define MEMORY_COPY_ERROR "Failed to copy memory."

#define GENERATE_ERROR(message) Error(message, __FILE__, __LINE__)
#define THROW_ERROR(message) throw GENERATE_ERROR(message);

#define THROW_ERROR_INFO(errorCode)							\
	{														\
		TCHAR pMessageBuffer[256] = { 0 }; 					\
		FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM,			\
			nullptr,										\
			errorCode,										\
			0,												\
			(LPSTR) pMessageBuffer, 256,					\
			nullptr);										\
		THROW_ERROR((char*) pMessageBuffer);				\
	}														\

#define THROW_LAST_ERROR() THROW_ERROR_INFO(GetLastError())

	/// <summary>
	/// Error showing pop up.
	/// </summary>
	class Error : public std::runtime_error
	{
	private:
		unsigned int _lineNumber = 0;
		const char* _fileName = nullptr;

	public:
		/// <summary>
		/// Default Contructor.
		/// </summary>
		/// <param name="message">The message to show on pop up.</param>
		Error(const std::string& message, const char* fileName, unsigned int lineNumber);
		/// <summary>
		/// Deleted copy constructor.
		/// </summary>
		/// <param name="error">Object to copy from.</param>
		Error(const Error& error) = delete;
		/// <summary>
		/// Deleted move contrcutor.
		/// </summary>
		/// <param name="error">Object to move from.</param>
		Error(Error&& error) = delete;
		/// <summary>
		/// Show the error pop up.
		/// </summary>
		virtual void Show() const noexcept;
		/// <summary>
		/// Gets the stored error message.
		/// </summary>
		/// <returns>Error message.</returns>
		virtual std::string What() const noexcept;
		/// <summary>
		/// Overriden Destructor.
		/// </summary>
		virtual ~Error() noexcept override;
		/// <summary>
		/// Deleted copy assignment operator.
		/// </summary>
		/// <param name="rhs">The value to copy from.</param>
		/// <returns>Copied value.</returns>
		Error& operator=(const Error& rhs) = delete;
		/// <summary>
		/// Deleted move assignment operator.
		/// </summary>
		/// <param name="rhs">The object to move from.</param>
		/// <returns>Moved value.</returns>
		Error& operator=(Error&& rhs) = delete;
		static void Log(const std::string& message) noexcept;
		static void ResetLogCursor() noexcept;
	};
}