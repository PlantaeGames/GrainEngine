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
		throw Error(MEMORY_ALLOCATION_ERROR);
	}
	errno_t result = 0;
	result = wcscpy_s(tempName, (rsize_t) lengthOfNameString + 1, name);
	if (result != 0)
	{
		// error
		//char errorMessageBuffer[256] = { 0 };
		//strerror_s(errorMessageBuffer, 256, result);
		throw Error(MEMORY_COPY_ERROR);
	}
	_name = tempName;

	// registering class
	WNDCLASSEXW wndClass = { 0 };
	wndClass.lpszClassName = name;
	wndClass.cbSize = sizeof(WNDCLASSEXW);
	wndClass.lpfnWndProc = wndProc;

	ATOM classId = RegisterClassExW(&wndClass);
	if (classId == 0)
	{
		// error
		throw Error(WINDOW_CLASS_REGISTRATION_ERROR);
	}
	_classId = classId;

	// creating window
	RECT size = { 0, 0, (long) width, (long) height };
	AdjustWindowRectEx(&size, WS_OVERLAPPEDWINDOW, false, false);
	HMODULE hModule = nullptr;
	if (GetModuleHandleExW(0, nullptr, &hModule) == false)
	{
		// error
		throw Error(WINDOW_GET_MODULE_HANDLE_ERROR);
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
		throw Error(WINDOW_CREATION_ERROR);
	}
	_handle = hWnd;
}

bool Window::PeekAndDispatchMessage(MSG* pMsg) const noexcept
{
	PeekMessageW(pMsg, _handle, 0, 0, PM_REMOVE);
	TranslateMessage(pMsg);
	DispatchMessageW(pMsg);

	return pMsg->message != WM_QUIT;
}

void Window::Show() const noexcept
{
	ShowWindow(_handle, SW_SHOW);
}

void Window::Hide() const noexcept
{
	ShowWindow(_handle, SW_HIDE);
}

Window::~Window()
{
	delete[] _name;
}

Window::Window(const Window& oldInstance)
{
	// copying name
	size_t lengthOfName = wcslen(oldInstance._name);
	wchar_t* nameCopyLocation = (wchar_t*) malloc(lengthOfName * sizeof(wchar_t) + 2);
	if (nameCopyLocation == nullptr)
	{
		// error
		throw Error(MEMORY_ALLOCATION_ERROR);
	}
	errno_t result = 0;
	result = wcscpy_s(nameCopyLocation, lengthOfName + 1, oldInstance._name);
	if (result != 0)
	{
		// error
		throw Error(MEMORY_COPY_ERROR);
	}
	_name = nameCopyLocation;

	// coping class id
	_classId = oldInstance._classId;

	// creating window
	RECT size = { 0 };
	if (GetWindowRect(oldInstance._handle, &size) == false)
	{
		// error
		throw Error(WINDOW_GET_RECT_ERROR);
	}
	unsigned int x = size.left;
	unsigned int y = size.top;
	AdjustWindowRectEx(&size, WS_OVERLAPPEDWINDOW, false, false);
	HMODULE hModule = nullptr;
	if (GetModuleHandleExW(0, nullptr, &hModule) == false)
	{
		// error
		throw Error(WINDOW_GET_MODULE_HANDLE_ERROR);
	}
	HWND hWnd = CreateWindowExW(0,
		_name,
		_name,
		WS_OVERLAPPEDWINDOW,
		x, y, size.right - size.left, size.bottom - size.top,
		nullptr, nullptr, hModule, nullptr);
	if (hWnd == nullptr)
	{
		// error
		throw Error(WINDOW_CREATION_ERROR);
	}
	_handle = hWnd;
}

Window& Window::operator=(Window& rightHandSide)
{
	*this = rightHandSide;
	return *this;
}