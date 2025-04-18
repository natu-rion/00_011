#include<windows.h>
#include<cstdint>
//ウィンドウプロシージャ
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg,
	WPARAM wparam, LPARAM lparam) {
	switch (msg) {
		//ウィンドウが破棄された
	case WM_DESTROY:
		// OSに対して、アプリの終了を伝える

		PostQuitMessage(0);
		return 0;

	}

	//標準のメッセージ処理を行う
	return DefWindowProc(hwnd, msg, wparam, lparam);


}

//
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	WNDCLASS wc{};
	//
	wc.lpfnWndProc = WindowProc;
	//
	wc.lpszClassName = L"CG2WindowClass";
	//
	wc.hInstance = GetModuleHandle(nullptr);
	//
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

	RegisterClass(&wc);

	//
	const int32_t kClientWidth = 1280;
	const int32_t kClientHeight = 720;

	//
	RECT wrc = { 0,0,kClientWidth,kClientHeight };

	//
	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);

	//
	HWND hwnd = CreateWindow(
		wc.lpszClassName,
		L"CG2",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		wrc.right - wrc.left,
		wrc.bottom - wrc.top,
		nullptr,
		nullptr,
		wc.hInstance,
		nullptr);

	//

	ShowWindow(hwnd, SW_SHOW);


	MSG msg{};
	//

	while (msg.message != WM_QUIT) {
		//
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);

		} else {
			//
		}





	}


	OutputDebugStringA("Hello,DirectX!\n");

	return 0;
}