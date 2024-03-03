#include "Movement.h"

namespace GrainEngine::ECS::Scripts
{
	void Movement::Update()
	{
		float deltaTime = Time::GetInstance().GetDeltaTime();

		_pMParent->pMTransform->rotation.x += _mouseDir.y * deltaTime * 100;
		_pMParent->pMTransform->rotation.y += _mouseDir.y * deltaTime * 100;

		if (_pRKeyboard->GetKey(Key::Q))
		{
			_pMParent->pMTransform->position.y += _speed * deltaTime;
		}
		
		if (_pRKeyboard->GetKey(Key::E))
		{
			_pMParent->pMTransform->position.y -= _speed * deltaTime;

		}

		if (_pRKeyboard->GetKey(Key::W))
		{
			_pMParent->pMTransform->position.z += _speed * deltaTime;
		}

		if (_pRKeyboard->GetKey(Key::S))
		{
			_pMParent->pMTransform->position.z -= _speed * deltaTime;
		}

		if (_pRKeyboard->GetKey(Key::D))
		{
			_pMParent->pMTransform->position.x += _speed * deltaTime;
		}

		if (_pRKeyboard->GetKey(Key::A))
		{
			_pMParent->pMTransform->position.x -= _speed * deltaTime;
		}

		_mouseDir = (_mouseDir - _pRMouse->GetCursorPosition()).Normalized();

		Error::Log("Position: " + _pMParent->pMTransform->position.ToString() + "\n");
		Error::Log("Rotion: " + _pMParent->pMTransform->rotation.ToString() + "\n");
		Error::Log("Scale: " + _pMParent->pMTransform->scale.ToString());
	}

	void Movement::Awake(ManagedObject<Entity>& pMEntity)
	{
		_pMParent = pMEntity;
	}

	Movement::Movement() :
		IComponent(),
		_pRKeyboard(InputManager::GetInstance().GetDevice<Keyboard>()),
		_pRMouse(InputManager::GetInstance().GetDevice<Mouse>())
	{}
}