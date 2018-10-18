// 作者：张孝谦
// 来源：可视化编程课件
// 说明：本程序用于说明创建Windows应用程序的方法及过程


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


#include <Windows.h>
#include <tchar.h>		// _T()

// 函数的前向声明
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // 窗口函数

// 入口函数
int WINAPI WinMain(HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPSTR lpszCmdLine,
					int nCmdShow)
{
	HWND hWnd;
	MSG msg;
	TCHAR szWindowClass[] = L"窗口示例";
	TCHAR szTitle[] = L"My Window";
	//LPCWSTR szWindowClass = TEXT("窗口");		// 窗口类名
	//LPCWSTR szTitle = TEXT("WindowTitle");	// 窗口标题名

	// 以下初始化窗口类
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);									// 窗口类的大小
	wcex.style = CS_HREDRAW | CS_VREDRAW;		// 窗口类型												// 窗口类型为默认类型
	wcex.lpfnWndProc = WndProc;											// 定义窗口处理函数
	wcex.cbClsExtra = 0;												// 窗口类无扩展
	wcex.cbWndExtra = 0;												// 窗口实例无扩展
	wcex.hInstance = hInstance;											// 当前实例句柄
	//wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));	// 窗口图标为默认图标
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);							// 窗口采用箭头光标
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);			// 注意类型转换；
	wcex.lpszMenuName = NULL;											// 窗口中无菜单
	wcex.lpszClassName = szWindowClass;									// 窗口类名为前述“窗口示例”
	//wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hIconSm = LoadIcon(hInstance, IDI_APPLICATION);			//窗口小图标为默认图标

	// 以下注册窗口类
	if (!RegisterClassEx(&wcex))		// 如果注册失败则发出警告
	{
		MessageBox(NULL, _T("窗口类注册失败！"), _T("窗口注册"), NULL);
		return 1;
	}
	//if (!RegisterClass(&wcex))		// 如果注册失败则发出警告
	//{
	//	MessageBeep(0);
	//	return FALSE;
	//}

	// 以下创建窗口
	hWnd = CreateWindow(
		szWindowClass,					// 窗口类名
		szTitle,						// 窗口实例的标题名
		WS_OVERLAPPEDWINDOW,			// 窗口的风格
		CW_USEDEFAULT, CW_USEDEFAULT,	// 窗口左上角坐标为默认值
		CW_USEDEFAULT, CW_USEDEFAULT,	// 窗口的宽高为默认值
		NULL,							// 此窗口无父窗口
		NULL,							// 此窗口无主菜单
		hInstance,						// 创建此窗口的应用程序的当前句柄
		NULL);							// 不使用该值

	if (!hWnd)							// 创建窗口失败则发出警告
	{
		MessageBox(NULL, _T("创建窗口失败！"), _T("创建窗口"), NULL);
		return 1;
	}
	ShowWindow(hWnd, nCmdShow);			// 显示窗口
	UpdateWindow(hWnd);					// 绘制用户区

	// 消息循环
	while (GetMessage(&msg, NULL, 0, 0))// 从消息队列读取消息并放在MSG结构中
	{
		TranslateMessage(&msg);			// 将消息的虚拟键转换为字符信息
		DispatchMessage(&msg);			// 将参数指向的消息传送到指定的窗口函数
	}									// GetMessage返回零值，循环结束
	
	return (int)msg.wParam;				// 消息循环结束即程序终止时将信息返回系统
}

// 以下定义窗口函数
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