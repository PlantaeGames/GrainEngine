#pragma once

#include <string>
#include <sstream>

#include "Vertex.h"

namespace GrainEngine::Structures
{
	template<typename t_T>
	class Point
	{
	public:
		t_T x = 0;
		t_T y = 0;

		Point() {}

		Point(t_T x, t_T y)
		{
			this->x = x;
			this->y = y;
		}

		operator Vertex() const noexcept
		{
			return Vertex((float)x, (float)y);
		}

		operator Vector2() const noexcept
		{
			return Vector2((float)x, (float)y);
		}

		operator Vector3() const noexcept
		{
			return Vector3((float)x, (float)y);
		}

		std::string ToString() const noexcept
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