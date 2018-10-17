// Win32Project1.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Win32Project1.h"

#define MAX_LOADSTRING 100

/*
	| ��������	| ˵��					|
	| --------- | --------------------- |
	| WORD		| 16λ�޷�������			|
	| LONG		| 32λ�з�������			|
	| DWORD		| 32λ�޷�������			|
	| HANDLE	| ���					|
	| UINT		| 32λ�޷�������			|
	| BOOL		| ����ֵ					|
	| LPTSTR	| ָ���ַ�����32λָ��	|
	| LPCTSTR	| ָ���ַ���������32λָ��|
*/

// ȫ�ֱ���: 
HINSTANCE hInst;                                // ��ǰʵ��
WCHAR szTitle[MAX_LOADSTRING];                  // �������ı�
WCHAR szWindowClass[MAX_LOADSTRING];            // ����������

// �˴���ģ���а����ĺ�����ǰ������: 
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,			// Ӧ�ó���ǰʵ�����
                     _In_opt_ HINSTANCE hPrevInstance,	// Ӧ�ó�������ʵ�����
                     _In_ LPWSTR    lpCmdLine,			// ָ����������в�����ָ��
                     _In_ int       nCmdShow)			// Ӧ�ó���ʼִ��ʱ������ʾ��ʽ������ֵ��ʶ
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: �ڴ˷��ô��롣

    // ��ʼ��ȫ���ַ���
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN32PROJECT1, szWindowClass, MAX_LOADSTRING);
	
	// ע�ᴰ����
    MyRegisterClass(hInstance);

    // ִ��Ӧ�ó����ʼ��: 
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT1));

    MSG msg;

    // ����Ϣѭ��: 
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);	// ����Ϣ�������ת��Ϊ�ַ���Ϣ
            DispatchMessage(&msg);	// ����Ϣ���͵�ָ�����ں���
        }
    }
	/*
		GetMessageW(
			_Out_ LPMSG lpMsg,			// ָ��MSG�ṹ��ָ��
			_In_opt_ HWND hWnd,			// ���ھ��
			_In_ UINT wMsgFilterMin,	// ������Ϣ���˵���С��Ϣ��ֵ
			_In_ UINT wMsgFilterMax);	// ������Ϣ���˵������Ϣ��ֵ
	*/

    return (int) msg.wParam;
}



//
//  ����: MyRegisterClass()
//
//  Ŀ��: ע�ᴰ���ࡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex; // ���������ݽṹ

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
		��Ӧ�ó����м���һ������ͼ�꣨ͼ����Դ���ڵ�ģ������ͼ����Դ����ϵͳԤ����ͼ���ʶ����
		HICON LoadCursor(HINSTANCE hInstance, LPCTSTR lpIconName)
		��Ӧ�ó����м���һ�����ڹ�꣨�����Դ���ڵ�ģ�����������Դ����ϵͳԤ�������ʶ����
		HBRUSH GetStockObject(int nBrush)
		Ӧ�ó�����ú���GetStockObject��ȡϵͳ�ṩ�ı���ˢ
	*/

    return RegisterClassExW(&wcex);
	// ע�ᴰ���ࣨ&������ṹ����ע��ɹ�������
}

//
//   ����: InitInstance(HINSTANCE, int)
//
//   Ŀ��: ����ʵ�����������������
//
//   ע��: 
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
   /*
	   CreateWindowExW(
			_In_ DWORD dwExStyle,			
			_In_opt_ LPCWSTR lpClassName,	// ��������
			_In_opt_ LPCWSTR lpWindowName,	// ���ڱ�����
			_In_ DWORD dwStyle,				// �������ڵ���ʽ
			_In_ int X,						// �������Ͻ�����
			_In_ int Y,						// �������Ͻ�����
			_In_ int nWidth,				// ���ڿ��
			_In_ int nHeight,				// ���ڸ߶�
			_In_opt_ HWND hWndParent,		// �ô��ڵĸ����ھ��
			_In_opt_ HMENU hMenu,			// �������˵����
			_In_opt_ HINSTANCE hInstance,	// �������ڵ�Ӧ�ó���ǰ���
			_In_opt_ LPVOID lpParam);		// ָ��һ�����ݸ����ڵĲ���ֵ��ָ��
   */

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);
   /*
		nCmdshowΪ������ʾ��ʽ��ʶ��
			SW_HIDE				���ش���
			SW_SHOWNORMAL		��ʾ�������
			SW_SHOWMINIMIZE		��ʾ����С������
			SW_SHOWMAXMIZE		��ʾ����󻯴���
			SW_SHOWNOACTIVE		��ʾ���������
			SW_RESTORE			�ָ�����ԭ����λ�ü��ߴ�
		��ʾ���ں�Ӧ�ó������UpdateWindow���²������û�����������WM_PAINT��Ϣ
   */

   return TRUE;
}

//
//  ����: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��:    ���������ڵ���Ϣ��
//
//  WM_COMMAND  - ����Ӧ�ó���˵�
//  WM_PAINT    - ����������
//  WM_DESTROY  - �����˳���Ϣ������
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // �����˵�ѡ��: 
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
            // TODO: �ڴ˴����ʹ�� hdc ���κλ�ͼ����...
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

// �����ڡ������Ϣ�������
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
