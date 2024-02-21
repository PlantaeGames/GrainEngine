#pragma once

#include <string>
#include <sstream>

#include "Vertex.h"

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

		operator Vertex() const
		{
			return Vertex((float)x, (float)y);
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