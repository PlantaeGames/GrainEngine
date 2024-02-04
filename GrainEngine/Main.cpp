#include "Main.h"

namespace GrainEngine
{
	int Main()
	{
		unsigned int exitCode = Engine::GetInstance().Start();

		Error::Log("Exited with Code: " + std::to_string(exitCode));
		return (int)exitCode;
	}
}