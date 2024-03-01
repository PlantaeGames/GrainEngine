#include "Movement.h"

namespace GrainEngine::ECS::Scripts
{
	void Movement::Update()
	{
		float deltaTime = Time::GetInstance().GetDeltaTime();

		if (_pRKeyboard->GetKey(_upKey))
		{
			_pMParent->pMTransform->position.z += _speed * deltaTime;
		}

		if (_pRKeyboard->GetKey(_downKey))
		{
			_pMParent->pMTransform->position.z -= _speed * deltaTime;

		}

		if (_pRKeyboard->GetKey(_rightKey))
		{
			_pMParent->pMTransform->position.x += _speed * deltaTime;
		}

		if (_pRKeyboard->GetKey(_leftKey))
		{
			_pMParent->pMTransform->position.x -= _speed * deltaTime;
		}

		Error::Log(_pMParent->pMTransform->position.ToString());
	}

	void Movement::Awake(ManagedObject<Entity>& pMEntity)
	{
		_pMParent = pMEntity;
	}

	Movement::Movement() :
		IComponent(),
		_pRKeyboard(InputManager::GetInstance().GetDevice<Keyboard>())
	{}
}