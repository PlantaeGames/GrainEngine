#include "Keyboard.h"

namespace GrainEngine::Input
{
	Keyboard::Keyboard() :
		InputDevice()
	{}

	void Keyboard::Add(Key key, bool keyUp) noexcept
	{
		InputDevice::Add(key, keyUp);
	}

	bool Keyboard::GetKey(Key key) const noexcept
	{
		return InputDevice::GetKey(key);
	}

	bool Keyboard::GetKeyDown(Key key) const noexcept
	{
		return InputDevice::GetKeyDown(key);
	}

	bool Keyboard::GetKeyUp(Key key) const noexcept
	{
		return InputDevice::GetKeyUp(key);
	}

	void Keyboard::Update() noexcept
	{
		InputDevice::Clear();
	}
}