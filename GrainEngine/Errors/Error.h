#pragma once

#include <stdexcept>
#include <assert.h>
#include <sstream>
#include <string>

#include <windows.h>

namespace GrainEngine::Errors
{
#define MEMORY_ALLOCATION_ERROR "Failed to allocate memory."
#define MEMORY_COPY_ERROR "Failed to copy memory."

#define GENERATE_ERROR(message) Error(message, __FILE__, __LINE__)
#define THROW_ERROR(message) throw GENERATE_ERROR(message);

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
		Error(const char* message, const char* fileName, unsigned int lineNumber);
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
		void Show() const noexcept;
		/// <summary>
		/// Gets the stored error message.
		/// </summary>
		/// <returns>Error message.</returns>
		std::string What() const noexcept;
		/// <summary>
		/// Overriden Destructor.
		/// </summary>
		~Error() noexcept override;
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
		static void Log(const char* message) noexcept;
	};
}