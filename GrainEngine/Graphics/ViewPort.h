#pragma once

#include "WinD3D.h"
#include "PipelineComponent.h"
#include "Structures/Rect.h"

namespace GrainEngine::Graphics
{
	using namespace GrainEngine::Structures;

	class ViewPort : PipelineComponent
	{
	public:
		ViewPort(const Rect rect);
		~ViewPort() noexcept override = default;

		void Bind() override;

	private:
		void Update() noexcept;

	private:
		D3D11_VIEWPORT _viewPort;

	public:
		Rect rect;
		float maxDepth = 1.0f;
		float minDepth = 0.0f;
	};
}