#include "PipelineState.h"

namespace GrainEngine::Graphics
{
	PipelineState::PipelineState(unsigned long long id,
		const std::string& vSFile, const std::string& pSFile,
		const Vertex* pVertices, unsigned int verticesCount) :
		_id(id),
		_material(vSFile, pSFile),
		_vertexBuffer()
	{
		_vertexBuffer.Create(pVertices, verticesCount);
	}
}