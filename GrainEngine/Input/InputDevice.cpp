#include "InputDevice.h"

namespace GrainEngine::Input
{
	InputDevice::InputDevice() :
		_keys(),
		_keysDown(),
		_keysUp()
	{}

	void InputDevice::Add(Key key, bool keyUp) noexcept
	{
		if (keyUp)
		{
			if (!GetKeyUp(key) && GetKey(key))
			{
				_keysUp.push_back(key);
				Remove(_keys, key);
			}

			return;
		}

		if (GetKey(key) == false)
		{
			_keys.push_back(key);
			_keysDown.push_back(key);
		}
	}

	bool InputDevice::Includes(const vector<Key>& container, Key key) const noexcept
	{
		for (auto k : container)
		{
			if (k == key)
			{
				return true;
			}
			continue;
		}
		return false;
	}

	void InputDevice::Remove(vector<Key>& container, Key key) noexcept
	{
		for (auto current = container.begin(), end = container.end(); current < end;)
		{
			if (*current == key)
			{
				current = container.erase(current);
				end = container.end();
			}
			else
			{
				++current;;
			}
		}
	}

	void InputDevice::Clear() noexcept
	{
		_keysDown.clear();
		_keysUp.clear();
	}

	bool InputDevice::GetKey(Key key) const noexcept
	{
		return Includes(_keys, key);
	}
	bool InputDevice::GetKeyDown(Key key) const noexcept
	{
		return Includes(_keysDown, key);
	}
	bool InputDevice::GetKeyUp(Key key) const noexcept
	{
		return Includes(_keysUp, key);
	}
}