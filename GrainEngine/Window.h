#pragma once

#include <wchar.h>
#include <stdexcept>

#include <windows.h>

#include "Error.h"

/// <summary>
/// Representing a window to be used with renderer.
/// </summary>
class Window
{
private:
	const wchar_t* Name = nullptr;
	ATOM ClassId;
	HWND Handle = nullptr;
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
};

