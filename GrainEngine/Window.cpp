#include "Window.h"

Window::Window(const wchar_t* name, 
	unsigned int x, unsigned int y, unsigned int width, unsigned int height,
	WNDPROC wndProc)
{
	// storing window and class name
	unsigned int lengthOfNameString = (unsigned int)wcslen(name);
	wchar_t* tempName = (wchar_t*) malloc((size_t) lengthOfNameString * sizeof(wchar_t) + 2);
	if (tempName == nullptr)
	{
		// error
		throw Error("ERROR: Unable to allocate memory.");
	}
	errno_t result = 0;
	result = wcscpy_s(tempName, (rsize_t) lengthOfNameString + 1, name);
	if (result != 0)
	{
		// error
		//char errorMessageBuffer[256] = { 0 };
		//strerror_s(errorMessageBuffer, 256, result);
		throw Error("ERROR: Unable to copy string.");
	}
	Name = tempName;

	// registering class
	WNDCLASSEXW wndClass = { 0 };
	wndClass.lpszClassName = name;
	wndClass.cbSize = sizeof(WNDCLASSEXW);
	wndClass.lpfnWndProc = wndProc;

	ATOM classId = RegisterClassExW(&wndClass);
	if (classId == 0)
	{
		// error
		throw Error("ERROR: Unable to register window class.");
	}
	ClassId = classId;

	// creating window
	RECT size = { 0, 0, (long) width, (long) height };
	AdjustWindowRectEx(&size, WS_OVERLAPPEDWINDOW, false, false);
	HMODULE hModule = nullptr;
	if (GetModuleHandleExW(0, nullptr, &hModule) == false)
	{
		// error
		throw Error("ERROR: Unable to retrive module handle.");
	}
	HWND hWnd = CreateWindowExW(0,
		name,
		name,
		WS_OVERLAPPEDWINDOW,
		x, y, size.right - size.left, size.bottom - size.top,
		nullptr, nullptr, hModule, nullptr);
	if (hWnd == nullptr)
	{
		// error
		throw Error("ERROR: Failed to Create Window.");
	}
	Handle = hWnd;
}

bool Window::PeekAndDispatchMessage(MSG* pMsg) const noexcept
{
	PeekMessageW(pMsg, nullptr, 0, 0, PM_REMOVE);
	TranslateMessage(pMsg);
	DispatchMessageW(pMsg);

	return pMsg->message != WM_QUIT;
}

void Window::Show() const noexcept
{
	ShowWindow(Handle, SW_SHOW);
}

void Window::Hide() const noexcept
{
	ShowWindow(Handle, SW_HIDE);
}

Window::~Window()
{
	free((void*) Name);
}