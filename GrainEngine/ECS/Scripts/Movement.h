#pragma once

#include "ECS/IComponent.h"
#include "ECS/Entity.h"
#include "Components/Time.h"
#include "Input/Key.h"
#include "Input/Keyboard.h"
#include "Input/Mouse.h"
#include "Structures/Vector2.h"
#include "Components/InputManager.h"

namespace GrainEngine::ECS::Scripts
{
	using namespace GrainEngine::ECS;
	using namespace GrainEngine::Input;
	using namespace GrainEngine::Components;
	using namespace GrainEngine::Structures;

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
		RefPtr<Mouse> _pRMouse;
	};
}