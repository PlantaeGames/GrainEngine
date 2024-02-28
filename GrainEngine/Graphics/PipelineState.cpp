#include "PipelineState.h"

#include "Pipeline.h"

namespace GrainEngine::Graphics
{
	PipelineState::PipelineState(unsigned long long id,
		const std::string& vSFile, const std::string& pSFile,
		const Vertex* pVertices, unsigned int verticesCount) :
		_id(id),
		_material(vSFile, pSFile),
		_vertexBuffer(),
		_verticesCount(verticesCount)
	{
		_vertexBuffer.Create(pVertices, verticesCount);
	}
}