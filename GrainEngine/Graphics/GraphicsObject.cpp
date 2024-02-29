#include "GraphicsObject.h"

namespace GrainEngine::Graphics
{
	GraphicsObject::GraphicsObject(unsigned long long id, const Material& material,
		const Vertex* pVerticies, unsigned int verticesCount) :
		_pipelineState(id, material, pVerticies, verticesCount)
	{}
}