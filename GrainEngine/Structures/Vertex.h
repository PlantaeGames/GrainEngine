#pragma once

namespace GrainEngine::Structures
{
	class Vertex
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

		Vertex() {}
	public:
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0;
	};
}