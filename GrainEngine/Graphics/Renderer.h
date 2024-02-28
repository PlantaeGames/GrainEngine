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

		void Add(GraphicsObject&& graphicsObject) const noexcept;
		void Remove(unsigned long long id) const;

	private:
		mutable Pipeline _pipeline;
	};
}