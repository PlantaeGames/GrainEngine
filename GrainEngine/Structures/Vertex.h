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
		}

		Vertex() {}
	public:
		float x = 0.0f;
		float y = 0.0f;
	};
}