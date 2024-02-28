#include "Mesh.h"

namespace GrainEngine::ECS::Components
{
	Mesh::Mesh() 
	{
		_pVertices = std::make_unique<Vertex[]>(_verticesCount);

		_pVertices[0] = { 0.0f, 0.5f };
		_pVertices[1] = { 0.5f, -0.5f };
		_pVertices[2] = { -0.5f, -0.5f };
	}
}