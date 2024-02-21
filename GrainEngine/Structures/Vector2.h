#pragma once

namespace GrainEngine::Structures
{
	class Vector3;

	class Vector2
	{
	public:
		Vector2() = default;
		Vector2(float x, float y);

		explicit operator Vector3() const noexcept;

		Vector2 Up() const noexcept;
		Vector2 Down() const noexcept;
		Vector2 Right() const noexcept;
		Vector2 Left() const noexcept;

	public:
		float x = 0.0f;
		float y = 0.0f;
	};
}