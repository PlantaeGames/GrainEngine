#include "Main.h"

namespace GrainEngine
{
	int Main()
	{
		unsigned int exitCode = std::make_unique<Engine>()->Start();

		Error::Log("Exited with Code: " + std::to_string(exitCode));
		return (int)exitCode;
	}
}