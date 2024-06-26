#include "Vector2.h"

#include "Vector3.h"
#include "Point.h"

namespace GrainEngine::Structures
{
	Vector2::Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Vector2::operator Vector3() const noexcept
	{
		return Vector3(x, y, 0.0f);
	}

	Vector2::operator Point() const noexcept
	{
		return Point((int)x, (int)y);
	}

	Vector2& Vector2::operator- (const Point& point) noexcept
	{
		x -= (int)point.y;
		y -= (int)point.y;

		return *this;
	}

	Vector2 Vector2::Normalized() noexcept
	{
		return Vector2(x / x == 0 ? 1 : std::abs(x), y / y == 0 ? 1 : std::abs(y));
	}

	Vector2 Vector2::Up() const noexcept
	{
		return Vector2(0.0f, 1.0f);
	}

	Vector2 Vector2::Down() const noexcept
	{
		return Vector2(0.0f, -1.0f);
	}

	Vector2 Vector2::Right() const noexcept
	{
		return Vector2(1.0f, 0.0f);
	}
	Vector2 Vector2::Left() const noexcept
	{
		return Vector2(-1.0f, 0.0f);
	}
}