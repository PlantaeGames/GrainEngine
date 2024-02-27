#include "PipelineComponent.h"

namespace GrainEngine::Graphics
{
	PipelineComponent::PipelineComponent() :
		_pDevice(Device::GetInstance().GetDevice()),
		_pDeviceContext(Device::GetInstance().GetDeviceContext())
	{}
}