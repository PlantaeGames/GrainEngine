#pragma once

#include <cmath>

#include "Vector2.h"

namespace GrainEngine::Structures
{
	class Vector3
	{
	public:
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;

		Vector3() {}

		explicit Vector3(float x)
		{
			this->x = x;
		}

		explicit Vector3(float x, float y)
		{
			this->x = x;
			this->y = y;
		}

		Vector3(float x, float y, float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		float Magnitude() const noexcept
		{
			using namespace std;

			return sqrtf(powf(x, 2.0f) + powf(y, 2.0f) + powf(z, 2.0f));
		}

		operator Vector2() const
		{
			return Vector2(x, y);
		}

		static Vector3 Zero() noexcept
		{
			return Vector3(0.0f, 0.0f, 0.0f);
		}

		static Vector3 Up() noexcept
		{
			return Vector3(0.0f, 1.0f, 0.0f);
		}

		static Vector3 Down() noexcept
		{
			return Vector3(0.0f, -1.0f, 0.0f);
		}

		static Vector3 Left() noexcept
		{
			return Vector3(-1.0f, 0.0f, 0.0f);
		}

		static Vector3 Right() noexcept
		{
			return Vector3(1.0f, 0.0f, 0.0f);
		}

		static Vector3 Forward() noexcept
		{
			return Vector3(0.0f, 0.0f, 1.0f);
		}

		static Vector3 Backward() noexcept
		{
			return Vector3(0.0f, 0.0f, -1.0f);
		}
	};
}