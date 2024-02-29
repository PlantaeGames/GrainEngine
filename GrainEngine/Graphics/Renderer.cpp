#include "Renderer.h"

namespace GrainEngine::Graphics
{
	PipelineState& Renderer::Add(GraphicsObject&& graphicsObject) const noexcept
	{
		return _pipeline.AddState(graphicsObject.GetState());
	}

	void Renderer::Remove(unsigned long long id) const
	{
		_pipeline.RemoveState(id);
	}

	void Renderer::PrepareRender()
	{
		_pipeline.PrepareRenderPass();
	}

	void Renderer::Render()
	{
		_pipeline.DoRenderPass();
	}

	Renderer::Renderer(HWND hWnd) :
		_pipeline(hWnd)
	{}
}