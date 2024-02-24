#pragma once

namespace GrainEngine::Graphics
{
	class IPipelineComponent
	{
	public:
		IPipelineComponent() = default;
		virtual ~IPipelineComponent() noexcept = default;

		virtual void Bind() = 0;
	};
}
