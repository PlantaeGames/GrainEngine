#pragma once

#include <cmath>

namespace GrainEngine::Structures
{
	class Vector2
	{
	public:
		float x = 0.0f;
		float y = 0.0f;

		Vector2() {}

		explicit Vector2(float x)
		{
			this->x = x;
		}

		Vector2(float x, float y)
		{
			this->x = x;
			this->y = y;
		}

		float Magnitude() const noexcept
		{
			using namespace std;

			return sqrtf(powf(x, 2.0f) + powf(y, 2.0f));
		}

		static Vector2 Zero() noexcept
		{
			return Vector2(0.0f, 0.0f);
		}

		static Vector2 Up() noexcept
		{
			return Vector2(0.0f, 1.0f);
		}

		static Vector2 Down() noexcept
		{
			return Vector2(0.0f, -1.0f);
		}

		static Vector2 Left() noexcept
		{
			return Vector2(-1.0f, 0.0f);
		}

		static Vector2 Right() noexcept
		{
			return Vector2(1.0f, 0.0f);
		}
	};
}