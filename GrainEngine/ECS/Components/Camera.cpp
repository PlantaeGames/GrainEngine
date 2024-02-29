#include "Camera.h"

namespace GrainEngine::ECS::Components
{
	void Camera::PreRender(const Renderer& renderer)
	{
		if (_init == false)
		{
			_pRPerspectivePoint = renderer.GetPerspectivePoint();
			_init = true;
		}

		// updates perspective point
		float transform[3][3] =
		{
			{_pMParent->pMTransform->position.x, _pMParent->pMTransform->position.y, _pMParent->pMTransform->position.z},
			{_pMParent->pMTransform->rotation.x, _pMParent->pMTransform->rotation.y, _pMParent->pMTransform->rotation.z},
			{_pMParent->pMTransform->scale.x, _pMParent->pMTransform->scale.y, _pMParent->pMTransform->scale.z}
		};

		_pRPerspectivePoint->position.x = transform[0][0];
		_pRPerspectivePoint->position.y = transform[0][1];
		_pRPerspectivePoint->position.z = transform[0][2];

		_pRPerspectivePoint->rotation.x = transform[1][0];
		_pRPerspectivePoint->rotation.y = transform[1][1];
		_pRPerspectivePoint->rotation.z = transform[1][2];

		_pRPerspectivePoint->scale.x = transform[2][0];
		_pRPerspectivePoint->scale.y = transform[2][1];
		_pRPerspectivePoint->scale.z = transform[2][2];
	}

	void Camera::Awake(ManagedObject<Entity>& pMEntity)
	{
		_pMParent = pMEntity;
	}
}