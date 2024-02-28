#include "Mesh.h"

namespace GrainEngine::ECS::Components
{
	Mesh::Mesh() :
		IComponent()
	{
		Random random = Random();

		_pVertices = std::make_unique<Vertex[]>(_verticesCount);

		(_pVertices.get())[0] = { 0.0f, 0.5f};
		(_pVertices.get())[1] = { 0.5f, -0.5f };
		(_pVertices.get())[2] = { -0.5f, -0.5f };
	}

	Mesh::~Mesh() noexcept {}
}