#include "Error.h"

Error::Error(const char* message) : std::runtime_error(message)
{
	ShowNotification();
}

const char* Error::What() const noexcept
{
	return this->what();
}

void Error::ShowNotification() const
{
	MessageBoxExA(nullptr, What(), "ERROR", MB_ICONERROR, 0);
}