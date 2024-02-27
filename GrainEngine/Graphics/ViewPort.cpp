#include "ViewPort.h"

namespace GrainEngine::Graphics
{
	void ViewPort::Bind(const ComPtr<ID3D11DeviceContext>& pDeviceContext)
	{
		Update();
		pDeviceContext->RSSetViewports(1u, &_viewPort);
	}

	void ViewPort::Update() noexcept
	{
		_viewPort.Width = rect.width;
		_viewPort.Height = rect.height;
		_viewPort.TopLeftX = rect.topLeftX;
		_viewPort.TopLeftY = rect.topLeftY;
		_viewPort.MinDepth = minDepth;
		_viewPort.MaxDepth = maxDepth;
	}

	ViewPort::ViewPort(const Rect rect) :
		PipelineComponent(),
		rect(rect)
	{
		Update();
	}
}