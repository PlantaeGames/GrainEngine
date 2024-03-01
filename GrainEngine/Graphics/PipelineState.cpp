#include "PipelineState.h"

#include "Pipeline.h"

namespace GrainEngine::Graphics
{
	PipelineState::PipelineState(unsigned long long id, const Material& material,
		const Vertex* pVerticies, unsigned int verticesCount,
		const unsigned int* pIndices, unsigned int indicesCount) :
		_id(id),
		_material(material),
		_vertexBuffer(),
		_indexBuffer(),
		_verticesCount(verticesCount),
		_indicesCount(indicesCount)
	{	
		_vertexBuffer.Create(pVerticies, verticesCount);
		_indexBuffer.Create(pIndices, indicesCount);
	}
}