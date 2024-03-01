#include "PerspectivePoint.h"

namespace GrainEngine::Graphics
{
	void PerspectivePoint::Update() const
	{
		PerspectiveConstantBuffer perspective = {};
		perspective.position = { 0.0f, 0.0f, 0.0f };
		perspective.rotation = { 0.0f, 0.0f, 0.0f };
		perspective.scale = { 0.0f, 0.0f, 0.0f };

		_perspectiveBuffer.Update(reinterpret_cast<char*>(&perspective));
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
		PerspectiveConstantBuffer perspective = {};
		perspective.position = { 0.0f, 0.0f, 0.0f };
		perspective.rotation = { 0.0f, 0.0f, 0.0f };
		perspective.scale = { 0.0f, 0.0f, 0.0f };

		_perspectiveBuffer.Create(0u, sizeof(PerspectiveConstantBuffer), 0u,
			reinterpret_cast<char*>(&perspective));
	}
}