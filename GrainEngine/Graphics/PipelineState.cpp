#include "PipelineState.h"

#include "Pipeline.h"

namespace GrainEngine::Graphics
{
	PipelineState::PipelineState(unsigned long long id, const Material& material,
		const Vertex* pVerticies, unsigned int verticesCount) :
		_id(id),
		_material(material),
		_vertexBuffer(),
		_verticesCount(verticesCount)
	{
		_vertexBuffer.Create(pVerticies, verticesCount);
	}
}