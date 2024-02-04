#include "Main.h"

namespace GrainEngine
{
	int Main()
	{
		unsigned int exitCode = Engine::GetInstance().Start();
		return (int)exitCode;
	}
}