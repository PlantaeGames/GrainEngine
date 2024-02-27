#include "PipelineComponent.h"

namespace GrainEngine::Graphics
{
	PipelineComponent::PipelineComponent() :
		_pDevice(Device::GetInstance().GetDevice())
	{}
}