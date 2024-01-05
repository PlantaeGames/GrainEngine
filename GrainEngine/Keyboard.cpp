#include "Keyboard.h"


Keyboard::Keyboard() :
	_keys(),
	_keysUp(),
	_keysDown()
{}

void Keyboard::Add(const Key key, bool keyUp) noexcept
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

void Keyboard::Clear() noexcept
{
	_keysUp.clear();
	_keysDown.clear();
}

bool Keyboard::Includes(const std::vector<Key>& container, const Key key) const noexcept
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

void Keyboard::Remove(std::vector<Key>& container, const Key key) noexcept
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

bool Keyboard::GetKey(const Key key) const noexcept
{
	return Includes(_keys, key);
}

bool Keyboard::GetKeyDown(const Key key) const noexcept
{
	return Includes(_keysDown, key);
}

bool Keyboard::GetKeyUp(const Key key) const noexcept
{
	return Includes(_keysUp, key);
}