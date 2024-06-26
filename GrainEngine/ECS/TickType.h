#pragma once

namespace GrainEngine::ECS
{
	enum class TickType
	{
		None,
		Awake,
		Start,
		Update,
		PreRender,
		PostRender,
		End
	};
}
