#include "InputManager.h"

namespace GrainEngine::Components
{
	InputManager::InputManager() :
		_inputDevices()
	{
		Register<Mouse>();
		Register<Keyboard>();
	}

	void InputManager::Feed(const MSG* const msg) noexcept
	{
		for (const auto& inputDevice : _inputDevices)
		{
			inputDevice->Feed(msg);
		}
	}

	bool InputManager::GetKeyDown(const Key key) const noexcept
	{
		return GetInput(key, KeyState::Down);
	}

	bool InputManager::GetKey(const Key key) const noexcept
	{
		return GetInput(key, KeyState::Hold);
	}

	bool InputManager::GetKeyUp(const Key key) const noexcept
	{
		return GetInput(key, KeyState::Up);
	}

	bool InputManager::GetInput(const Key key, const KeyState state) const noexcept
	{
		if (state == KeyState::Down)
		{
			for (const auto& inputDevice : _inputDevices)
			{
				if (inputDevice->GetKeyDown(key) == true) return true;
				else continue;
			}
		}
		else if (state == KeyState::Up)
		{
			for (const auto& inputDevice : _inputDevices)
			{
				if (inputDevice->GetKeyUp(key) == true) return true;
				else continue;
			}
		}
		else
		{
			for (const auto& inputDevice : _inputDevices)
			{
				if (inputDevice->GetKey(key) == true) return true;
				else continue;
			}
		}
		return false;
	}

	void InputManager::Update() const noexcept
	{
		for (const auto& inputDevice : _inputDevices)
		{
			inputDevice->Update();
		}
	}
}