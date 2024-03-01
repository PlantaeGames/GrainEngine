#pragma once

#include "Color.h"

namespace GrainEngine::Structures
{
	struct Vertex
	{
	public:
		Vertex(float x, float y)
		{
			this->x = x;
			this->y = y;
			this->z = 0.0f;
		}

		Vertex(float x, float y, float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		Vertex(float x, float y, float z, float r, float g, float b)
		{
			this->x = x;
			this->y = y;
			this->z = z;

			this->color = Color(r, g, b);
		}

		Vertex(float x, float y, float z, float r, float g, float b, float a)
		{
			this->x = x;
			this->y = y;
			this->z = z;

			this->color = Color(r, g, b, a);
		}

		Vertex() {}
	public:
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;
		Color color;
	};
}