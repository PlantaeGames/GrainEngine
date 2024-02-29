#include "PerspectivePoint.h"

namespace GrainEngine::Graphics
{
	void PerspectivePoint::Update() const
	{
		float transform[3][3] =
		{
			{position.x, position.y, position.z},
			{rotation.x, rotation.y, rotation.z},
			{scale.x, scale.y, scale.z}
		};

		_perspectiveBuffer.Update(reinterpret_cast<char*>(transform));
	}

	void PerspectivePoint::Bind()
	{
		_perspectiveBuffer.Bind();
	}

	PerspectivePoint::PerspectivePoint() :
		_perspectiveBuffer(ConstantBufferBindPosition::VertexShader),
		position(0.0f, 0.0f, 0.0f),
		rotation(0.0f, 0.0f, 0.0f),
		scale(1.0f, 1.0f, 1.0f)
	{
		float transform[3][3] =
		{
			{position.x, position.y, position.z},
			{rotation.x, rotation.y, rotation.z},
			{scale.x, scale.y, scale.z}
		};

		_perspectiveBuffer.Create(1u, reinterpret_cast<char*>(transform));
	}
}