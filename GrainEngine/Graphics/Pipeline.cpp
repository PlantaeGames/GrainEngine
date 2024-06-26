#include "Pipeline.h"

namespace GrainEngine::Graphics
{
	void Pipeline::RenderPass(PipelineState& pipelineState)
	{
		// switch state by binding pipeline components.
		pipelineState._vertexBuffer.Bind();
		pipelineState._indexBuffer.Bind();
		pipelineState._material.Bind();

		auto count = pipelineState._indicesCount;

		QUEUE_CHECK_THROW_D3D_ERROR_INFO(
			Device::GetInstance().GetDeviceContext()->DrawIndexed(count, 0u, 0);
		);
	}

	void Pipeline::DoRenderPass()
	{
		_perspectivePoint.Update();

		for (auto& state : _states)
		{
			RenderPass(state);
		}

		_swapChain.Present();
	}

	void Pipeline::PrepareRenderPass()
	{
		_swapChain.ClearScreen();
	}

	PipelineState& Pipeline::AddState(PipelineState&& pipelineState) noexcept
	{
		_states.push_back(pipelineState);
		return _states.back();
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
		_swapChain.Bind();
		_depthState.Bind();
		_viewPort.Bind();
		_inputLayout.Bind();
		_topology.Bind();
		_perspectivePoint.Bind();
	}

	Pipeline::Pipeline(const Window* pWindow) :
		_states(),
		_swapChain(pWindow),
		_depthState(),
		_viewPort(pWindow->GetBounds()),
		_inputLayout(VertexShader("Shaders\\Default\\Vertex.cso").GetBinary()),
		_topology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST),
		_perspectivePoint()
	{
		SetFixedStages();
	}
}