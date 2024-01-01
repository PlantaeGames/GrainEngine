#pragma once

#include <wchar.h>
#include <stdexcept>

#include <windows.h>

#include "Error.h"
#include "Random.h"
#include "Stopwatch.h"

#define WINDOW_CREATION_ERROR "Failed to create window."
#define WINDOW_CLASS_REGISTRATION_ERROR "Failed to register window."
#define WINDOW_GET_MODULE_HANDLE_ERROR "Failed to get handle to window."
#define WINDOW_GET_RECT_ERROR "Failed to get rect of the window."

/// <summary>
/// Representing a window to be used with renderer.
/// </summary>
class Window
{
private:
	const wchar_t* _name = nullptr;
	ATOM _classId = 0;
	HWND _handle = nullptr;
public:
	/// <summary>
	/// Default Window constructor.
	/// </summary>
	/// <param name="name">Name of the Window And class.</param>
	/// <param name="x">X position of the window.</param>
	/// <param name="y">Y position of the window.</param>
	/// <param name="width">Width of the client area.</param>
	/// <param name="height">Height of the client area.</param>
	/// <param name="wndProc">Message handler for this window.</param>
	Window(const wchar_t* name, 
		unsigned int x, unsigned int y, unsigned int width, unsigned int height,
		WNDPROC wndProc);
	/// <summary>
	/// Copy constructor for the window object.
	/// </summary>
	/// <param name="oldInstance">Reference to the instance to be copied.</param>
	Window(const Window& oldInstance);
	/// <summary>
	/// Obtains a message from queue, translate and dispatches to the message handler.
	/// </summary>
	/// <param name="pMsg">Pointer to MSG structure to hold current message.</param>
	/// <returns>If the quit is requested or not.</returns>
	bool PeekAndDispatchMessage(MSG* pMsg) const noexcept;
	/// <summary>
	/// Changes the window state to visible.
	/// </summary>
	void Show() const noexcept;
	/// <summary>
	/// Changes the window state to hidden.
	/// </summary>
	void Hide() const noexcept;
	/// <summary>
	/// Default Destrcutor of the window.
	/// </summary>
	~Window();
	/// <summary>
	/// Assignment operator.
	/// </summary>
	/// <param name="rhs">Assign to.</param>
	/// <returns>Assigned value.</returns>
	Window& operator=(Window& rhs);
private:
	/// <summary>
	/// Swaps it with other object.
	/// </summary>
	/// <param name="other">The object to swap to.</param>
	void Swap(Window& other) noexcept;
};

