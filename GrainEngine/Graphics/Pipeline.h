#pragma once

#include <vector>

#include "Windows.h"
#include "Swapchain.h"
#include "Device.h"
#include "PipelineState.h"
#include "ViewPort.h"
#include "InputLayout.h"
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

		void AddState(PipelineState&& pipelineState) noexcept;
		void RemoveState(unsigned long long id);

		void DoRenderPass();

	private:
		void PrepareRenderPass();
		void RenderPass(const PipelineState& pipelineState);

		void SetFixedStages();

		Rect GetWindowBounds(HWND hWnd);

	private:
		std::vector<PipelineState> _states;
		Swapchain _swapChain;
		ViewPort _viewPort;
		InputLayout _inputLayout;
	};
}