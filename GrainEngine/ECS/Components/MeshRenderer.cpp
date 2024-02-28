#include "MeshRenderer.h"

namespace GrainEngine::ECS::Components
{
	void MeshRenderer::PreRender(const Renderer& renderer)
	{
		// registering on renderer
		if (_registered)
			return;

		auto pMesh = _pMParent->GetComponent<Mesh>();

		renderer.Add(
			GraphicsObject(_id, 
				"Shaders\\Default\\Vertex.cso",
				"Shaders\\Default\\Pixel.cso",
				pMesh->GetVertices().Get(),
				pMesh->GetVerticesCount()
			));

		_registered = true;
	}

	void MeshRenderer::Awake(ManagedObject<Entity>& pMEntity)
	{
		_pMParent = pMEntity;
	}

	void MeshRenderer::End()
	{
		// un registering on renderer

		if (_registered == false) 
			return;
	}

	MeshRenderer::MeshRenderer() :
		IComponent()
	{}
}