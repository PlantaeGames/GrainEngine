#include "Pipeline.h"

namespace GrainEngine::Graphics
{

	void Pipeline::RenderPass(const PipelineState& pipelineState)
	{
		// switch stae by binding pipeline components.

		QUEUE_CHECK_THROW_D3D_ERROR_INFO(
			Device::GetInstance().GetDeviceContext()->Draw(0u, 0u);
		);
	}

	void Pipeline::DoRenderPass()
	{
		PrepareRenderPass();

		for (auto& state : _states)
		{
			RenderPass(state);
		}
	}

	void Pipeline::PrepareRenderPass()
	{
		_swapChain.ClearScreen();
	}

	void Pipeline::AddState(PipelineState&& pipelineState) noexcept
	{
		_states.push_back(pipelineState);
	}

	void Pipeline::RemoveState(unsigned long long id)
	{
		for (auto current = _states.begin(); current != _states.end(); ++current)
		{
			if (current->GetId() != id)
				continue;

			_states.erase(current);

			return;
		}

		THROW_PIPELINE_STATE_NOT_FOUND_GRAPHICS_ERROR(PIPELINE_STATE_NOT_FOUND_GRAPHICS_ERROR_MESSAGE);
	}

	void Pipeline::SetFixedStages()
	{
		_viewPort.Bind();
		_inputLayout.Bind();
	}

	Rect Pipeline::GetWindowBounds(HWND hWnd)
	{
		RECT rect = { 0 };
		if (!GetWindowRect(hWnd, &rect))
		{
			THROW_LAST_ERROR();
		}

		return { 0.0f, 0.0f, (float)(rect.right - rect.left), (float) (rect.bottom - rect.top)};
	}

	Pipeline::Pipeline(HWND hWnd) :
		_states(),
		_swapChain(hWnd),
		_viewPort(GetWindowBounds(hWnd)),
		_inputLayout(VertexShader("Shaders\\Default\\VertexShader.cso").GetBinary())
	{
		SetFixedStages();
	}
}