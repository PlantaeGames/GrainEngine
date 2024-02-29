#pragma once

#include "WinD3D.h"
#include "Pipeline.h"
#include "GraphicsObject.h"

namespace GrainEngine::Graphics
{
	class Renderer
	{
	public:
		Renderer(HWND hWnd);
		~Renderer() noexcept = default;

		void Render();
		void PrepareRender();

		PipelineState& Add(GraphicsObject&& graphicsObject) const noexcept;
		void Remove(unsigned long long id) const;

		PerspectivePoint& GetPerspectivePoint() const noexcept
		{
			return _pipeline.GetPerspectivePoint();
		}

	private:
		mutable Pipeline _pipeline;
	};
}