#include "MeshRenderer.h"

namespace GrainEngine::ECS::Components
{
	void MeshRenderer::PreRender(const Renderer& renderer)
	{
		if (_registered)
		{
			TransformConstantBuffer transform = {};
			transform.position = { _pMParent->pMTransform->position.x, _pMParent->pMTransform->position.y, _pMParent->pMTransform->position.z };
			transform.rotation = { _pMParent->pMTransform->rotation.x, _pMParent->pMTransform->rotation.y, _pMParent->pMTransform->rotation.z };
			transform.scale = { _pMParent->pMTransform->scale.x, _pMParent->pMTransform->scale.y, _pMParent->pMTransform->scale.z };
			
			// update Transform
			_pRPipelineState->GetMaterial().GetVertexShader().UpdateTransform(transform);
		}

		// registering on renderer
		if (_registered)
			return;

		auto pMesh = _pMParent->GetComponent<Mesh>();

		_pRPipelineState = renderer.Add(
			GraphicsObject(_id, 
				Material("Shaders\\Default\\Vertex.cso", "Shaders\\Default\\Pixel.cso"),
				pMesh->GetVertices().Get(), pMesh->GetVerticesCount()
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