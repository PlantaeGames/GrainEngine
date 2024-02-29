#pragma once

#include "ECS/IComponent.h"
#include "ECS/Entity.h"
#include "Components/Time.h"
#include "Input/Key.h"
#include "Input/Keyboard.h"
#include "Components/InputManager.h"

namespace GrainEngine::ECS::Scripts
{
	using namespace GrainEngine::ECS;
	using namespace GrainEngine::Input;
	using namespace GrainEngine::Components;

	class Movement : public IComponent
	{
	public:
		Movement();
		~Movement() noexcept override = default;
		
		void Awake(ManagedObject<Entity>& _pMEntity) override;
		void Update() override;

	private:
		ManagedObject<Entity> _pMParent;
		float _speed = 1.0f;

		RefPtr<Keyboard> _pRKeyboard;

		Key _upKey = Key::Up;
		Key _downKey = Key::Down;
		Key _rightKey = Key::Right;
		Key _leftKey = Key::Left;
	};
}