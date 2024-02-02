#include "InputManager.h"

namespace GrainEngine::Components
{
	InputManager::InputManager() :
		_inputDevices()
	{}

	void InputManager::Feed(const MSG* const msg) noexcept
	{
		for (const auto& inputDevice : _inputDevices)
		{
			inputDevice->Feed(msg);
		}
	}

	void InputManager::Update() const noexcept
	{
		for (const auto& inputDevice : _inputDevices)
		{
			inputDevice->Update();
		}
	}
}