#pragma once

namespace GrainEngine::Structures
{
	struct Color
	{
	public:
		Color(float r, float g, float b)
		{
			this->r = r;
			this->g = g;
			this->b = b;
			this->a = 1.0f;
		}

		Color(float r, float g, float b, float a)
		{
			this->r = r;
			this->g = g;
			this->b = b;
			this->a = a;
		}

		Color() {}
	public:
		float r = 0.0f;
		float g = 0.0f;
		float b = 0.0f;
		float a = 0.0f;
	};
}