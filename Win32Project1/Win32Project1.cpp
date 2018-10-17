// Win32Project1.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "Win32Project1.h"

#define MAX_LOADSTRING 100

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

// 全局变量: 
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

// 此代码模块中包含的函数的前向声明: 
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,			// 应用程序当前实例句柄
                     _In_opt_ HINSTANCE hPrevInstance,	// 应用程序其他实例句柄
                     _In_ LPWSTR    lpCmdLine,			// 指向程序命令行参数的指针
                     _In_ int       nCmdShow)			// 应用程序开始执行时窗口显示方式的整数值标识
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此放置代码。

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN32PROJECT1, szWindowClass, MAX_LOADSTRING);
	
	// 注册窗口类
    MyRegisterClass(hInstance);

    // 执行应用程序初始化: 
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT1));

    MSG msg;

    // 主消息循环: 
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);	// 将消息的虚拟键转换为字符信息
            DispatchMessage(&msg);	// 将消息传送到指定窗口函数
        }
    }
	/*
		GetMessageW(
			_Out_ LPMSG lpMsg,			// 指向MSG结构的指针
			_In_opt_ HWND hWnd,			// 窗口句柄
			_In_ UINT wMsgFilterMin,	// 用于消息过滤的最小消息号值
			_In_ UINT wMsgFilterMax);	// 用于消息过滤的最大消息号值
	*/

    return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex; // 窗口类数据结构

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32PROJECT1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	/*
		HICON LoadIcon(HINSTANCE hInstance, LPCTSTR lpIconName)
		在应用程序中加载一个窗口图标（图标资源所在的模块句柄，图标资源名或系统预定义图标标识名）
		HICON LoadCursor(HINSTANCE hInstance, LPCTSTR lpIconName)
		在应用程序中加载一个窗口光标（光标资源所在的模块句柄，光标资源名或系统预定义光标标识名）
		HBRUSH GetStockObject(int nBrush)
		应用程序调用函数GetStockObject获取系统提供的背景刷
	*/

    return RegisterClassExW(&wcex);
	// 注册窗口类（&窗口类结构），注册成功返回真
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释: 
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
   /*
	   CreateWindowExW(
			_In_ DWORD dwExStyle,			
			_In_opt_ LPCWSTR lpClassName,	// 窗口类名
			_In_opt_ LPCWSTR lpWindowName,	// 窗口标题名
			_In_ DWORD dwStyle,				// 创建窗口的样式
			_In_ int X,						// 窗口左上角坐标
			_In_ int Y,						// 窗口左上角坐标
			_In_ int nWidth,				// 窗口宽度
			_In_ int nHeight,				// 窗口高度
			_In_opt_ HWND hWndParent,		// 该窗口的父窗口句柄
			_In_opt_ HMENU hMenu,			// 窗口主菜单句柄
			_In_opt_ HINSTANCE hInstance,	// 创建窗口的应用程序当前句柄
			_In_opt_ LPVOID lpParam);		// 指向一个传递给窗口的参数值的指针
   */

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);
   /*
		nCmdshow为窗口显示形式标识：
			SW_HIDE				隐藏窗口
			SW_SHOWNORMAL		显示并激活窗口
			SW_SHOWMINIMIZE		显示并最小化窗口
			SW_SHOWMAXMIZE		显示并最大化窗口
			SW_SHOWNOACTIVE		显示但不激活窗口
			SW_RESTORE			恢复窗口原来的位置及尺寸
		显示窗口后，应用程序调用UpdateWindow更新并绘制用户区，并发出WM_PAINT消息
   */

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:    处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 分析菜单选择: 
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 在此处添加使用 hdc 的任何绘图代码...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
	
    return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
