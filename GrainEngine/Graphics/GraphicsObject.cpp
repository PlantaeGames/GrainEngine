#include "GraphicsObject.h"

namespace GrainEngine::Graphics
{
	GraphicsObject::GraphicsObject(unsigned long long id,
		const std::string& vSFile, const std::string& pSFile,
		const Vertex* pVerticies, unsigned int verticesCount) :
		_pipelineState(id, vSFile, pSFile, pVerticies, verticesCount)
	{}
}