#pragma once

#include <string>

#include "Errors/Error.h"

namespace GrainEngine::Input::Errors
{
#define GENERATE_INPUT_DEVICE_NOT_FOUND_ERROR(message) InputDeviceNotFoundError(message, __FILE__, __LINE__)
#define THROW_INPUT_DEVICE_NOT_FOUND_ERROR(message) throw GENERATE_INPUT_DEVICE_NOT_FOUND_ERROR(message)

	class InputDeviceNotFoundError : GrainEngine::Errors::Error
	{
	public:
		InputDeviceNotFoundError(const std::string& message, const char* fileName, unsigned int lineNumber);
		~InputDeviceNotFoundError() noexcept override = default;

		InputDeviceNotFoundError(const InputDeviceNotFoundError& otherInstance) = delete;
		InputDeviceNotFoundError(InputDeviceNotFoundError&& oldInstance) noexcept = delete;

		InputDeviceNotFoundError& operator= (const InputDeviceNotFoundError& otherInstance) = delete;
		InputDeviceNotFoundError& operator= (InputDeviceNotFoundError&& oldInstance) noexcept = delete;
	};
}
