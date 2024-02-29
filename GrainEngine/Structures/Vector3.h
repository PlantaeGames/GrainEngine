#pragma once

#include <string>

namespace GrainEngine::Structures
{
	class Vector2;

	class Vector3
	{
	public:
		Vector3() = default;

		Vector3(float x, float y, float z);

		explicit operator Vector2() const noexcept;

		std::string ToString() const noexcept;

		Vector3 Up() const noexcept;
		Vector3 Down() const noexcept;
		Vector3 Right() const noexcept;
		Vector3 Left() const noexcept;
		Vector3 Inward() const noexcept;
		Vector3 Outward() const noexcept;

	public:
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;
	};
}