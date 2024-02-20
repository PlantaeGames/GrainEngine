#pragma once

#include "Point.h"
#include "Vector2.h"
#include "Vector3.h"

namespace GrainEngine::Structures
{
	class Vertex
	{
	public:
		float x = 0.0f;
		float y = 0.0f;

		Vertex(float x, float y)
		{
			this->x = x;
			this->y = y;
		}

		explicit operator Vector2() const noexcept
		{
			return Vector2(x, y);
		}

		explicit operator Vector3() const noexcept
		{
			return Vector3(x, y, 0.0f);
		}

		explicit operator Point<float>() const noexcept
		{
			return Point<float>(x, y);
		}
	};
}