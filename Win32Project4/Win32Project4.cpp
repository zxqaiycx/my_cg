// 作者：张孝谦
// 来源：可视化编程课本
// 说明：本程序为Windows图形设备接口及Windows绘图的应用实例

/*
	| 数据类型	| 说明								|
	| --------- | --------------------------------- |
	| WORD		| 16位无符号整数						|
	| DWORD		| 32位无符号整数						|
	| LONG		| 32位有符号整数						|
	| UINT		| 32位无符号整数						|
	| BOOL		| 布尔值								|
	| HANDLE	| 句柄								|
	| UINT		| 32位无符号整数						|
	| BOOL		| 布尔值								|
	| LPSTR		| 指向字符串的32位指针				|
	| LPCSTR	| 指向字符串常量的32位指针			|
	| LPTSTR	| 指向字符串的32位指针（Unicode）		|
	| LPCTSTR	| 指向字符串常量的32位指针（Unicode）	|
*/
/*
	| 编码类型	| 常量表达形式	| 变量表达形式	| 字符复制	| 字符连接	| 字符比较	|
	|-----------|---------------|---------------|-----------|-----------|-----------|
	| SBCS/MBCS	| "string"		| char			| strcpy	| strcat	| strcmp	|
	| Unicode	| L"string"		| wchar_t		| wcscpy	| wcscat	| wcscmp	|
	| 统一处理	| _T("string")	| TCHAR			| _tcscpy	| _tcscat	| _ tcscmp	|
*/
/*
	```
	typedef struct tagWNDCLASSEXW {
		UINT        cbSize;
		// Win 3.x
		UINT        style;
		WNDPROC     lpfnWndProc;
		int         cbClsExtra;
		int         cbWndExtra;
		HINSTANCE   hInstance;
		HICON       hIcon;
		HCURSOR     hCursor;
		HBRUSH      hbrBackground;
		LPCWSTR     lpszMenuName;
		LPCWSTR     lpszClassName;
		// Win 4.0
		HICON       hIconSm;
	} WNDCLASSEXW;
	```
*/

#include <Windows.h>
#include <tchar.h>

BOOLEAN InitWindow(HINSTANCE hInstance, int nCmdShow);	// 初始化窗口类并创建窗口
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// 窗口函数

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	InitWindow(hInstance, nCmdShow);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

// 初始化窗口类并创建窗口
BOOLEAN InitWindow(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	TCHAR szWindowClass[]	= _T("窗口示例");
	TCHAR szTitle[]			= _T("映射模式及填充实例图");

	WNDCLASSEX wcex;
	wcex.cbSize			= sizeof(WNDCLASSEX);
	wcex.style			= 0;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(hInstance, IDI_APPLICATION);
	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL, _T("窗口类注册失败！"), _T("窗口注册"), NULL);
		return FALSE;
	}

	hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL,
		hInstance,
		NULL);
	if (!hWnd)
	{
		MessageBox(NULL, _T("创建窗口失败！"), _T("创建窗口"), NULL);
		return FALSE;
	}
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

// 窗口函数
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




















