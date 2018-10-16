// 作者：略
// 来源：可视化编程课件
// 说明：本程序用于说明创建Windows应用程序的方法及过程

#include <Windows.h>

// 函数的前向声明
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // 窗口函数

int WINAPI WinMain(HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPSTR lpszCmdLine,
					int nCmdShow)
{
	HWND hWnd;
	MSG msg;
	LPCWSTR szClassName = TEXT("窗口");		// 窗口类名
	LPCWSTR szTitle = TEXT("WindowTitle");	// 窗口标题名

	// 初始化窗口类
	WNDCLASS wc;
	wc.style = 0;					// 窗口类型为默认类型
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szClassName;

	// 注册窗口类
	if (!RegisterClass(&wc))
	{
		MessageBeep(0);
		return FALSE;
	}

	// 创建窗口
	hWnd = CreateWindow(szClassName,
						szTitle,
						WS_OVERLAPPEDWINDOW,
						CW_USEDEFAULT,
						CW_USEDEFAULT,
						CW_USEDEFAULT,
						CW_USEDEFAULT,
						NULL,
						NULL,
						hInstance,
						NULL);
	// 显示窗口
	ShowWindow(hWnd, nCmdShow);
	// 绘制用户区

	// 消息循环
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
		break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}