#pragma once

#include "WinD3D.h"
#include "ConstantBuffer.h"
#include "PipelineComponent.h"
#include "Structures/Vector3.h"

namespace GrainEngine::Graphics
{
	using namespace GrainEngine::Structures;

	class PerspectivePoint : public PipelineComponent
	{

	public:
		PerspectivePoint();
		~PerspectivePoint() noexcept = default;

		void Bind() override;
		void Update() const;

	private:
		mutable ConstantBuffer _perspectiveBuffer;

	public:
		Vector3 position;
		Vector3 rotation;
		Vector3 scale;
	};
}