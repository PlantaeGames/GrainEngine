#pragma once

#include <string>
#include <sstream>

#include "Vertex.h"
#include "Vector2.h"

namespace GrainEngine::Structures
{
	class Point
	{
	public:
		int x = 0;
		int y = 0;

	public:
		Point(int x, int y)
		{
			this->x = x;
			this->y = y;
		}

		Point() {}

		operator Vector2() const noexcept
		{
			return Vector2((float)x, (float)y);
		}

		Point& operator- (const Point& rhs) noexcept
		{
			x -= rhs.x;
			y -= rhs.y;

			return *this;
		}

		Point Normalized() const noexcept
		{
			return Point(x / (x == 0? 1 : std::abs(x)), y / (y == 0 ? 1 : std::abs(y)));
		}

		std::string ToString()
		{
			std::stringstream string;
			string << "Point: { ";
			string << "x = ";
			string << x;
			string << ", ";
			string << "y = ";
			string << y;
			string << " }";

			return string.str();
		}
	};
}