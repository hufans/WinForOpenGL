#include "ggl.h"
LRESULT CALLBACK GLWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
			PostQuitMessage(0);
			return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

//ÐÞ¸Ä²âÊÔ
INT WINAPI WinMain(HINSTANCE histance, HINSTANCE hPre, LPSTR lpCmLime, int nShowCmd)
{
	WNDCLASSEX wnddoss;
	wnddoss.cbClsExtra = 0;
	wnddoss.cbSize = sizeof(WNDCLASSEX);
	wnddoss.cbWndExtra = 0;
	wnddoss.hbrBackground = NULL;
	wnddoss.hCursor = LoadCursor(NULL, IDC_ARROW);
	wnddoss.hIcon = NULL;
	wnddoss.hIconSm = NULL;
	wnddoss.hInstance = histance;
	wnddoss.lpfnWndProc = GLWindowProc;
	wnddoss.lpszClassName = L"GLWindow";
	wnddoss.lpszMenuName = NULL;
	wnddoss.style = CS_VREDRAW | CS_HREDRAW;
	ATOM atom = RegisterClassEx(&wnddoss);
	if (!atom)
	{
		MessageBox(NULL, L"Register Fail", L"ERROR", MB_OK);
		return 0;
	}

	RECT rect;
	rect.left = 0;
	rect.right = 800;
	rect.top = 0;
	rect.bottom = 600;
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, NULL);
	int windowWidth = rect.right - rect.left;
	int windowHeight = rect.bottom - rect.top;

	HWND hwnd = CreateWindowEx(NULL, L"GLWindow", L"OPenGL Window", WS_OVERLAPPEDWINDOW,
		100, 100, windowWidth, windowHeight,
		NULL, NULL, histance, NULL);
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);
	MSG msg;

	while (true)
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return 0;
}
