#pragma once

#include <stdexcept>
#include <windows.h>

class Error : std::runtime_error
{
public:
	Error(const char* message);
	const char* What() const noexcept;
private:
	void ShowNotification() const;
};

