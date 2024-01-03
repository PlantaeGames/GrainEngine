#include "Window.h"

Window::Window(const wchar_t* name, 
	unsigned int x, unsigned int y, unsigned int width, unsigned int height,
	WNDPROC wndProc)
{
	// storing window and class name
	unsigned int lengthOfNameString = (unsigned int)wcslen(name);
	assert(lengthOfNameString > 0);

	wchar_t* tempName = new wchar_t[lengthOfNameString * sizeof(wchar_t) + 2];
	if (tempName == nullptr)
	{
		// error
		THROW_ERROR(MEMORY_ALLOCATION_ERROR);
	}
	errno_t result = 0;
	result = wcscpy_s(tempName, (rsize_t) lengthOfNameString + 1, name);
	if (result != 0)
	{
		// error
		THROW_ERROR(MEMORY_COPY_ERROR);
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
		THROW_ERROR(WINDOW_CLASS_REGISTRATION_ERROR);
	}
	_classId = classId;

	// creating window
	RECT size = { 0, 0, (long) width, (long) height };
	AdjustWindowRectEx(&size, WS_OVERLAPPEDWINDOW, false, false);
	HMODULE hModule = nullptr;
	if (GetModuleHandleExW(0, nullptr, &hModule) == false)
	{
		// error
		THROW_ERROR(WINDOW_GET_MODULE_HANDLE_ERROR);
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
		THROW_ERROR(WINDOW_CREATION_ERROR);
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

Window::~Window() noexcept
{
	HINSTANCE hModule = nullptr;
	GetModuleHandleExW(0, nullptr, &hModule);
	UnregisterClassW(_name, hModule);

	delete _name;
}

Window::Window(const Window& oldInstance)
{
	// copying name
	size_t lengthOfName = wcslen(oldInstance._name);
	wchar_t* nameCopyLocation = new wchar_t[lengthOfName * sizeof(wchar_t) + 2];
	if (nameCopyLocation == nullptr)
	{
		// error
		THROW_ERROR(MEMORY_ALLOCATION_ERROR);
	}
	errno_t result = 0;
	result = wcscpy_s(nameCopyLocation, lengthOfName + 1, oldInstance._name);
	if (result != 0)
	{
		// error
		THROW_ERROR(MEMORY_COPY_ERROR);
	}
	_name = nameCopyLocation;

	// coping class id
	_classId = oldInstance._classId;

	// creating window
	RECT size = { 0 };
	if (GetWindowRect(oldInstance._handle, &size) == false)
	{
		// error
		THROW_ERROR(WINDOW_GET_RECT_ERROR);
	}
	unsigned int x = size.left;
	unsigned int y = size.top;
	AdjustWindowRectEx(&size, WS_OVERLAPPEDWINDOW, false, false);
	HMODULE hModule = nullptr;
	if (GetModuleHandleExW(0, nullptr, &hModule) == false)
	{
		// error
		THROW_ERROR(WINDOW_GET_MODULE_HANDLE_ERROR);
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
		THROW_ERROR(WINDOW_CREATION_ERROR);
	}
	_handle = hWnd;
}

Window& Window::operator=(const Window& rhs)
{
	Window tempCopy(rhs);

	Swap(tempCopy);
	return *this;
}

void Window::Swap(Window& other) noexcept
{
	using std::swap;

	swap(_name, other._name);
	swap(_classId, other._classId);
	swap(_handle, other._handle);
}

Window::Window(Window&& oldInstance) noexcept : Window::Window()
{
	Swap(oldInstance);
}

Window& Window::operator=(Window&& rhs) noexcept
{
	Swap(rhs);
	return *this;
}