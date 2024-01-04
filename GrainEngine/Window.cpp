#include "Window.h"

LRESULT CALLBACK WndProcInit(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProcStub(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

Window::Window(const wchar_t* name, 
	unsigned int x, unsigned int y, unsigned int width, unsigned int height)
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

	// creating window
	Create(x, y, width, height);
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
	DestroyWindow(_handle);

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

	// creating window
	RECT size = { 0 };
	if (GetWindowRect(oldInstance._handle, &size) == false)
	{
		// error
		THROW_ERROR(WINDOW_GET_RECT_ERROR);
	}
	unsigned int x = size.left;
	unsigned int y = size.top;

	Create(x, y, size.right - size.left, size.bottom - size.top);
}

Window& Window::operator=(const Window& rhs)
{
	return *this = std::move(Window(rhs));
}

void Window::Swap(Window& other) noexcept
{
	using std::swap;

	swap(_name, other._name);
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

void Window::Create(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
	// creating window
	RECT size = { 0, 0, (long)width, (long)height };
	AdjustWindowRectEx(&size, WS_OVERLAPPEDWINDOW, false, false);
	HMODULE hModule = nullptr;
	if (GetModuleHandleExW(0, nullptr, &hModule) == false)
	{
		// error
		THROW_ERROR(WINDOW_GET_MODULE_HANDLE_ERROR);
	}
	HWND hWnd = CreateWindowExW(0,
		WindowClass::GetInstance().GetName(),
		_name,
		WS_OVERLAPPEDWINDOW,
		x, y, size.right - size.left, size.bottom - size.top,
		nullptr, nullptr, hModule, this);
	if (hWnd == nullptr)
	{
		// error
		THROW_ERROR(WINDOW_CREATION_ERROR);
	}
	_handle = hWnd;
}

LRESULT Window::WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (msg == WM_CLOSE)
	{
		PostQuitMessage(UI_EXITCODE);
		return 0;
	}

	return DefWindowProcW(hWnd, msg, wParam, lParam);
}

LRESULT CALLBACK WndProcStub(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	auto* const pWindow = reinterpret_cast<Window*>(GetWindowLongPtrW(hWnd, GWLP_USERDATA));
	return pWindow->WindowProc(hWnd, msg, wParam, lParam);
}

LRESULT CALLBACK WndProcInit(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// attached to window class.
	if (msg == WM_NCCREATE)
	{
		const auto* const createStruct = reinterpret_cast<CREATESTRUCTW*>(lParam);
		auto* const window = static_cast<Window*>(createStruct->lpCreateParams);

		LONG_PTR result = 0;
		result = SetWindowLongPtrW(hWnd, GWLP_USERDATA, (LONG_PTR) window);
		result = SetWindowLongPtrW(hWnd, GWLP_WNDPROC, (LONG_PTR) WndProcStub);

		if (result == 0)
		{
			// error
			THROW_ERROR(WINDOW_SET_LONGPTR_ERROR);
		}

		return window->WindowProc(hWnd, msg, wParam, lParam);
	}

	return DefWindowProcW(hWnd, msg, wParam, lParam);
}

Window::WindowClass::WindowClass()
{
	Register();
}

void Window::WindowClass::Register()
{
	// registering class
	WNDCLASSEXW wndClass = { 0 };
	wndClass.lpszClassName = _name;
	wndClass.cbSize = sizeof(WNDCLASSEXW);
	wndClass.lpfnWndProc = WndProcInit;

	ATOM classId = RegisterClassExW(&wndClass);
	if (classId == 0)
	{
		// error
		THROW_ERROR(WINDOW_CLASS_REGISTRATION_ERROR);
	}
	_id = classId;
	HMODULE hModule = nullptr;
	if (GetModuleHandleExW(0, nullptr, &hModule) == false)
	{
		// error
		THROW_ERROR(WINDOW_GET_MODULE_HANDLE_ERROR);
	}
	_hInstance = hModule;
}

const wchar_t* Window::WindowClass::GetName() const noexcept
{
	return _name;
}

ATOM Window::WindowClass::GetID() const noexcept
{
	return _id;
}

Window::WindowClass::~WindowClass() noexcept
{
	UnregisterClassW(_name, _hInstance);
}

const Window::WindowClass& Window::WindowClass::GetInstance() noexcept
{
	static WindowClass instance;
	return instance;
}