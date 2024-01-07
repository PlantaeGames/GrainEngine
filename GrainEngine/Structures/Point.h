#pragma once

#include <string>
#include <sstream>

namespace GrainEngine::Structures
{
	template<typename T>
	struct Point
	{
		T x = 0;
		T y = 0;

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