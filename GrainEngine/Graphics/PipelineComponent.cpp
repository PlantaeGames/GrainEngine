#include "PipelineComponent.h"

namespace GrainEngine::Graphics
{
	PipelineComponent::PipelineComponent(const ComPtr<ID3D11Device>& pDevice) :
		_pDevice(pDevice)
	{}
}