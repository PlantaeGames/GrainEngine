#pragma once

#include <list>

#include "Windows.h"
#include "Swapchain.h"
#include "DepthState.h"
#include "Device.h"
#include "PipelineState.h"
#include "ViewPort.h"
#include "InputLayout.h"
#include "PrimitiveTopology.h"
#include "PerspectivePoint.h"
#include "Graphics/Errors/PipelineStateNotFoundGraphicsError.h"

namespace GrainEngine::Graphics
{
#define PIPELINE_STATE_NOT_FOUND_GRAPHICS_ERROR_MESSAGE "Pipeline State Not Found."

	using namespace GrainEngine::Errors;
	using namespace GrainEngine::Graphics::Errors;

	class Pipeline
	{
	public:
		Pipeline(HWND hWnd);
		~Pipeline() noexcept = default;

		PipelineState& AddState(PipelineState&& pipelineState) noexcept;
		void RemoveState(unsigned long long id);

		void PrepareRenderPass();
		void DoRenderPass();

		PerspectivePoint& GetPerspectivePoint() noexcept
		{
			return _perspectivePoint;
		}

	private:
		void RenderPass(PipelineState& pipelineState);

		void SetFixedStages();

		Rect GetWindowBounds(HWND hWnd);

	private:
		std::list<PipelineState> _states;
		Swapchain _swapChain;
		DepthState _depthState;
		ViewPort _viewPort;
		InputLayout _inputLayout;
		PrimitiveTopology _topology;
		PerspectivePoint _perspectivePoint;
	};
}