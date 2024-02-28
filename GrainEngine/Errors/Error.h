#pragma once

#include <stdexcept>
#include <assert.h>
#include <sstream>
#include <string>
#include <vector>

#include <windows.h>

#include "DebugConsole.h"
#include "Misc/RefPtr.h"

namespace GrainEngine::Errors
{
#define MEMORY_ALLOCATION_ERROR "Failed to allocate memory."
#define MEMORY_COPY_ERROR "Failed to copy memory."

#define THROW(error) throw error
#define GENERATE_ERROR(message) Error(message, __FILE__, __LINE__)
#define THROW_ERROR(message)  THROW(GENERATE_ERROR(message))

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

	using namespace GrainEngine::Misc;

	/// <summary>
	/// Error showing pop up.
	/// </summary>
	class Error : public std::runtime_error
	{
	private:
		unsigned int _lineNumber = 0;
		std::string _fileName;
		std::vector<std::string> _information;
	public:
		/// <summary>
		/// Default Contructor.
		/// </summary>
		/// <param name="message">The message to show on pop up.</param>
		Error(const std::string& message, const std::string& fileName, unsigned int lineNumber);
		/// <summary>
		///  Copy constructor.
		/// </summary>
		/// <param name="error">Object to copy from.</param>
		Error(const Error& error) = default;
		/// <summary>
		/// Move contrcutor.
		/// </summary>
		/// <param name="error">Object to move from.</param>
		Error(Error&& error) noexcept = default;
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
		/// Appends message to the error.
		/// </summary>
		/// <param name="message">The message to append</param>
		void Append(const std::string& message) noexcept;
		/// <summary>
		/// Overriden Destructor.
		/// </summary>
		virtual ~Error() noexcept override = default;
		/// <summary>
		/// Copy assignment operator.
		/// </summary>
		/// <param name="rhs">The value to copy from.</param>
		/// <returns>Copied value.</returns>
		Error& operator=(const Error& rhs) = default;
		/// <summary>
		/// Move assignment operator.
		/// </summary>
		/// <param name="rhs">The object to move from.</param>
		/// <returns>Moved value.</returns>
		Error& operator=(Error&& rhs) noexcept = default;
		static void Log(const std::string& message) noexcept;
		static void ResetLogCursor() noexcept;
		static void ClearLog() noexcept;
	};
}