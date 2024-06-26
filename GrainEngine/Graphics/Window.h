#pragma once

#include <wchar.h>
#include <stdexcept>
#include <utility>
#include <assert.h>

#include <windows.h>

#include "Errors/Error.h"
#include "Structures/Rect.h"

namespace GrainEngine::Graphics
{
#define WINDOW_CREATION_ERROR "Failed to create window."
#define WINDOW_CLASS_REGISTRATION_ERROR "Failed to register window."
#define WINDOW_GET_MODULE_HANDLE_ERROR "Failed to get handle to window."
#define WINDOW_GET_RECT_ERROR "Failed to get rect of the window."

#define UI_EXITCODE 1

	using namespace GrainEngine::Errors;
	using namespace GrainEngine::Structures;

	/// <summary>
	/// Representing a window to be used with renderer.
	/// </summary>
	class Window
	{
	private:
		class WindowClass
		{
		public:
			WindowClass(const WindowClass& otherInstance) = delete;
			WindowClass(WindowClass&& oldInstance) noexcept = delete;
			WindowClass& operator= (const WindowClass& otherInstance) = delete;
			WindowClass&& operator= (WindowClass&& oldInstance) = delete;

			static const WindowClass& GetInstance() noexcept;
			const wchar_t* GetName() const noexcept;
			ATOM GetID() const noexcept;
		private:
			WindowClass();
			void Register();
			~WindowClass() noexcept;
		private:
			const wchar_t* const _name = L"GrainEngine";
			ATOM _id = 0;
			HINSTANCE _hInstance = nullptr;
		};

	protected:
		const wchar_t* _name = nullptr;
		HWND _handle = nullptr;
	public:
		/// <summary>
		/// Window constructor.
		/// </summary>
		/// <param name="name">Name of the Window And class.</param>
		/// <param name="x">X position of the window.</param>
		/// <param name="y">Y position of the window.</param>
		/// <param name="width">Width of the client area.</param>
		/// <param name="height">Height of the client area.</param>
		/// <param name="wndProc">Message handler for this window.</param>
		Window(const wchar_t* name,
			unsigned int x, unsigned int y, unsigned int width, unsigned int height);
		/// <summary>
		/// Copy constructor for the window object.
		/// </summary>
		/// <param name="oldInstance">Reference to the instance to be copied.</param>
		Window(const Window& oldInstance);
		/// <summary>
		/// Move constructor for the window object.
		/// </summary>
		/// <param name="oldInstance">Object to be moved from.</param>
		Window(Window&& oldInstance) noexcept;
		/// <summary>
		/// Obtains a message from queue, translate and dispatches to the message handler.
		/// </summary>
		/// <param name="pMsg">Pointer to MSG structure to hold current message.</param>
		/// <returns>If the quit is requested or not.</returns>
		virtual bool PeekAndDispatchMessage(MSG* pMsg) const noexcept;
		/// <summary>
		/// Changes the window state to visible.
		/// </summary>
		void Show() const noexcept;
		/// <summary>
		/// Changes the window state to hidden.
		/// </summary>
		void Hide() const noexcept;
		Rect GetBounds() const;
		/// <summary>
		/// Obtains Handle of the Window.
		/// </summary>
		/// <returns>Handle of the window.</returns>
		const HWND GetHandle() const noexcept;
		/// <summary>
		/// Assignment operator for copying.
		/// </summary>
		/// <param name="rhs">Assign to.</param>
		/// <returns>Assigned value.</returns>
		Window& operator=(const Window& rhs);
		/// <summary>
		/// Assignment operator for moving.
		/// </summary>
		/// <param name="rhs">Object to be moved from.</param>
		/// <returns>Moved value.</returns>
		Window& operator=(Window&& rhs) noexcept;
	private:
		/// <summary>
		/// Default compiler generated contructor.
		/// </summary>
		void Create(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
		friend LRESULT WndProcInit(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
		friend LRESULT WndProcStub(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	protected:
		Window() = default;
		/// <summary>
		/// Default Destrcutor of the window.
		/// </summary>
		virtual ~Window() noexcept;
		/// <summary>
		/// Swaps it with other object.
		/// </summary>
		///	<param name="other">The object to swap to.</param>
		virtual void Swap(Window& other) noexcept;
		virtual LRESULT WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	};
}