#include "Movement.h"

namespace GrainEngine::ECS::Scripts
{
	void Movement::Update()
	{
		float deltaTime = Time::GetInstance().GetDeltaTime();

		if (_pRKeyboard->GetKey(Key::A))
		{
			_pMParent->pMTransform->rotation.z += _speed * deltaTime;
		}

		if (_pRKeyboard->GetKey(Key::D))
		{
			_pMParent->pMTransform->rotation.z -= _speed * deltaTime;

		}

		if (_pRKeyboard->GetKey(Key::W))
		{
			_pMParent->pMTransform->position.y += _speed * deltaTime;
		}

		if (_pRKeyboard->GetKey(Key::S))
		{
			_pMParent->pMTransform->position.y -= _speed * deltaTime;

		}

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

		Error::Log("Position: " + _pMParent->pMTransform->position.ToString() + "\n");
		Error::Log("Rotation: " + _pMParent->pMTransform->rotation.ToString());
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