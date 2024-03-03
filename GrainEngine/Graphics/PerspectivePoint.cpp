#include "PerspectivePoint.h"

namespace GrainEngine::Graphics
{
	void PerspectivePoint::Update() const
	{
		PerspectiveConstantBuffer perspective = {};
		perspective.position = position;
		perspective.rotation = rotation;
		perspective.scale = scale;
		perspective.aspectRatio = aspectRatio;
		perspective.fov = fov;
		perspective.nearPlane = nearPlane;
		perspective.farPlane = farPlane;

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
		scale(1.0f, 1.0f, 1.0f),
		aspectRatio(600.0f/800.0f),
		fov(70.0f),
		nearPlane(1.0f),
		farPlane(1000.0f)

	{
		PerspectiveConstantBuffer perspective = {};
		perspective.position = position;
		perspective.rotation = rotation;
		perspective.scale = scale;
		perspective.aspectRatio = aspectRatio;
		perspective.fov = fov;
		perspective.nearPlane = nearPlane;
		perspective.farPlane = farPlane;

		_perspectiveBuffer.Create(1u, sizeof(PerspectiveConstantBuffer), 0u,
			reinterpret_cast<char*>(&perspective));
	}
}