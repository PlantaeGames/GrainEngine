#include "PrimitiveTopology.h"

namespace GrainEngine::Graphics
{
	void PrimitiveTopology::Bind()
	{
		_pDeviceContext->IASetPrimitiveTopology(_topology);
	}

	PrimitiveTopology::PrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY topology) :
		PipelineComponent(),
		_topology(topology)
	{}
}