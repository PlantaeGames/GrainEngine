#include "Vector3.h"

#include "Vector2.h"

namespace GrainEngine::Structures
{
	Vector3::Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3::operator Vector2() const noexcept
	{
		return Vector2(x, y);
	}

	Vector3 Vector3::Up() const noexcept
	{
		return Vector3(0.0f, 1.0f, 0.0f);
	}

	Vector3 Vector3::Down() const noexcept
	{
		return Vector3(0.0f, -1.0f, 0.0f);
	}

	Vector3 Vector3::Right() const noexcept
	{
		return Vector3(1.0f, 0.0f, 0.0f);
	}
	Vector3 Vector3::Left() const noexcept
	{
		return Vector3(-1.0f, 0.0f, 0.0f);
	}

	Vector3 Vector3::Inward() const noexcept
	{
		return Vector3(0.0f, 0.0f, 1.0f);
	}

	Vector3 Vector3::Outward() const noexcept
	{
		return Vector3(0.0f, 0.0f, -1.0f);
	}
}