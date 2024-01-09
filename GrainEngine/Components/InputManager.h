#pragma once

#include <list>
#include <memory>

#include <windows.h>

#include "Patterns/Singleton.h"
#include "Input/Mouse.h"
#include "Input/Keyboard.h"
#include "Errors/Error.h"

namespace GrainEngine::Components
{
#define INPUT_DEVICE_NOT_FOUND_ERROR "Requested input device not registerd."

	using namespace Patterns;
	using namespace Input;
	using namespace Errors;

	using std::unique_ptr;

	class InputManager : public Singleton<InputManager>
	{
		friend Singleton;
	private:
		enum class KeyState
		{
			Up,
			Down,
			Hold
		};
	public:
		InputManager(const InputManager& otherInstance) noexcept = delete;
		InputManager(InputManager&& oldInstance) noexcept = delete;
		InputManager& operator= (const InputManager& otherInstance) = delete;
		InputManager& operator= (InputManager&& oldInstance) noexcept = delete;

		void Feed(const MSG* const msg) noexcept;
		
		bool GetKeyDown(const Key key) const noexcept;
		bool GetKeyUp(const Key key) const noexcept;
		bool GetKey(const Key key) const noexcept;

		void Update() const noexcept;
	private:
		InputManager();
		~InputManager() noexcept override = default;

		template<typename t_InputDevice>
		void Register() noexcept
		{
			_inputDevices.push_back(std::move(std::make_unique<t_InputDevice>()));
		}

		template<typename t_InputDevice>
		void UnRegister()
		{
			for (const auto& inputDevice : _inputDevices)
			{
				if (dynamic_cast<t_InputDevice>(&inputDevice) == nullptr)
					continue;

				_inputDevices.remove(inputDevice);
				return;
			}

			THROW_ERROR(INPUT_DEVICE_NOT_FOUND_ERROR);
		}

		bool GetInput(const Key key, const KeyState state) const noexcept;

	private:
		std::list<unique_ptr<InputDevice>> _inputDevices;
	};
}

