// 作者：张孝谦
// 来源：可视化编程课件
// 说明：本程序用于说明创建Windows应用程序的方法及过程

/*
	| 基本数据类型			| 二进制位	| 值域		|	
	| --------------------- | --------- | --------- |
	| (signed) char			| 8			|			|
	| unsigned char			| 8			|			|
	| (signed) int			| 16		|			|
	| unsigned int			| 16		|			|
	| (signed) short int	| 16		|			|
	| unsigned short int	| 16		|			|
	| (signed) long int		| 32		|			|
	| unsigned long int		| 32		|			|
	| float					| 32		| 7位有效位	|
	| double				| 64		| 15位有效位	|
	| long double			| 89		| 19位有效位	|
*/
/*
	| 数据类型	| 说明					|
	| --------- | --------------------- |
	| WORD		| 16位无符号整数			|
	| LONG		| 32位有符号整数			|
	| DWORD		| 32位无符号整数			|
	| HANDLE	| 句柄					|
	| UINT		| 32位无符号整数			|
	| BOOL		| 布尔值					|
	| LPTSTR	| 指向字符串的32位指针	|
	| LPCTSTR	| 指向字符串常量的32位指针|
*/
/*
	
*/

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
	wc.lpfnWndProc = WndProc;		// 定义窗口处理函数
	wc.cbClsExtra = 0;				// 窗口类无扩展
	wc.cbWndExtra = 0;				// 窗口实例无扩展
	wc.hInstance = hInstance;		// 当前实例句柄
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// 窗口的最小化图标为默认图标
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// 窗口采用箭头光标
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 注意类型转换；窗口背景为白色，BLACK_BRUSH也可以
	wc.lpszMenuName = NULL;			// 窗口中无菜单
	wc.lpszClassName = szClassName;	// 窗口类名为前述“窗口”

	// 注册窗口类
	if (!RegisterClass(&wc))		// 如果注册失败则发出警告
	{
		MessageBeep(0);
		return FALSE;
	}

	// 创建窗口
	hWnd = CreateWindow(szClassName,		// 窗口类名
						szTitle,			// 窗口实例的标题名
						WS_OVERLAPPEDWINDOW,// 窗口的风格
						CW_USEDEFAULT,		// 窗口左上角图标为默认值
						CW_USEDEFAULT,
						CW_USEDEFAULT,		// 窗口的宽高为默认值
						CW_USEDEFAULT,
						NULL,				// 此窗口无父窗口
						NULL,				// 此窗口无主菜单
						hInstance,			// 创建此窗口的应用程序的当前句柄
						NULL);				// 不使用该值
	// 显示窗口
	ShowWindow(hWnd, nCmdShow);
	// 绘制用户区

	// 消息循环
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;	// 消息循环结束即程序终止时将信息返回系统
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