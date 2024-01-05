#pragma once

#include <vector>

#include <windows.h>

class Keyboard
{
public:
	enum class Key
	{
		Up = VK_UP,
		Down = VK_DOWN,
		Right = VK_RIGHT,
		Left = VK_LEFT
	};
	Keyboard();
	constexpr Keyboard(const Keyboard& otherInstance) = delete;
	constexpr Keyboard(Keyboard&& oldInstance) noexcept = delete;
	void Add(const Key key, bool keyUp = false) noexcept;
	void Clear() noexcept;
	bool GetKey(const Key key) const noexcept;
	bool GetKeyDown(const Key key) const noexcept;
	bool GetKeyUp(const Key key) const noexcept;
	constexpr Keyboard& operator= (const Keyboard& otherInstance) = delete;
	constexpr Keyboard& operator= (Keyboard&& oldInstance) noexcept = delete;
	constexpr ~Keyboard() noexcept = default;
private:
	bool Includes(const std::vector<Key>& container, const Key key) const noexcept;
	void Remove(std::vector<Key>& container, const Key key) noexcept;
private:
	std::vector<Key> _keys;
	std::vector<Key> _keysUp;
	std::vector<Key> _keysDown;
};

