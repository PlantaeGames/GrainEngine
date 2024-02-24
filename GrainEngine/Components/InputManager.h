#pragma once

#include <list>
#include <memory>

#include <windows.h>

#include "Patterns/Singleton.h"
#include "Input/Mouse.h"
#include "Input/Keyboard.h"
#include "Input/Errors/InputDeviceNotFoundError.h"

namespace GrainEngine::Components
{
#define INPUT_DEVICE_NOT_FOUND_ERROR_MESSAGE "Requested input device not registerd."

	using namespace Patterns;
	using namespace Input;
	using namespace GrainEngine::Input::Errors;

	using std::unique_ptr;

	class InputManager : public Singleton<InputManager>
	{
		friend Singleton;

	public:
		InputManager(const InputManager& otherInstance) = delete;
		InputManager(InputManager&& oldInstance) noexcept = delete;
		InputManager& operator= (const InputManager& otherInstance) = delete;
		InputManager& operator= (InputManager&& oldInstance) noexcept = delete;

		void Feed(const MSG* const msg) noexcept;

		void Update() const noexcept;

		template<typename t_InputDevice>
		const t_InputDevice& GetDevice() const
		{
			return *static_cast<t_InputDevice*>(FindDevice<t_InputDevice>().get());
		}

		template<typename t_InputDevice>
		void RegisterDevice() noexcept
		{
			AddDevice<t_InputDevice>();
		}

		template<typename t_InputDevice>
		void UnRegisterDevice()
		{
			RemoveDevice<t_InputDevice>();
		}

	private:
		InputManager();
		~InputManager() noexcept override = default;

		template<typename t_InputDevice>
		const unique_ptr<InputDevice>& FindDevice() const
		{
			for (const auto& inputDevice : _inputDevices)
			{
				if (dynamic_cast<t_InputDevice*>(inputDevice.get()) == nullptr)
					continue;

				return inputDevice;
			}

			THROW_INPUT_DEVICE_NOT_FOUND_ERROR(INPUT_DEVICE_NOT_FOUND_ERROR_MESSAGE);
		}

		template<typename t_InputDevice>
		void AddDevice() noexcept
		{
			_inputDevices.push_back(std::move(std::make_unique<t_InputDevice>((unsigned int)_inputDevices.size())));
		}

		template<typename t_InputDevice>
		void RemoveDevice()
		{
			_inputDevices.remove(FindDevice<t_InputDevice>());
		}

	private:
		std::list<unique_ptr<InputDevice>> _inputDevices;
	};
}

