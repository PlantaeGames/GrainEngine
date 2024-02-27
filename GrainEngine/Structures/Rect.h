#pragma once

namespace GrainEngine::Structures
{
	struct Rect
	{
	public:
		float width = 0.0f;
		float height = 0.0f;
		float topLeftX = 0.0f;
		float topLeftY = 0.0f;

	public:
		Rect() {}
		Rect(float width, float height, float topLeftX, float topLeftY)
		{
			this->width = width;
			this->height = height;
			this->topLeftX = topLeftX;
			this->topLeftY = topLeftY;
		}
	};
}