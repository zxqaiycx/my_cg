// ���ߣ���Тǫ
// ��Դ�����ӻ���̿α�
// ˵����������ΪWindowsͼ���豸�ӿڼ�Windows��ͼ��Ӧ��ʵ��

/*
	| ��������	| ˵��								|
	| --------- | --------------------------------- |
	| WORD		| 16λ�޷�������						|
	| DWORD		| 32λ�޷�������						|
	| LONG		| 32λ�з�������						|
	| UINT		| 32λ�޷�������						|
	| BOOL		| ����ֵ								|
	| HANDLE	| ���								|
	| UINT		| 32λ�޷�������						|
	| BOOL		| ����ֵ								|
	| LPSTR		| ָ���ַ�����32λָ��				|
	| LPCSTR	| ָ���ַ���������32λָ��			|
	| LPTSTR	| ָ���ַ�����32λָ�루Unicode��		|
	| LPCTSTR	| ָ���ַ���������32λָ�루Unicode��	|
*/
/*
	| ��������	| ���������ʽ	| ���������ʽ	| �ַ�����	| �ַ�����	| �ַ��Ƚ�	|
	|-----------|---------------|---------------|-----------|-----------|-----------|
	| SBCS/MBCS	| "string"		| char			| strcpy	| strcat	| strcmp	|
	| Unicode	| L"string"		| wchar_t		| wcscpy	| wcscat	| wcscmp	|
	| ͳһ����	| _T("string")	| TCHAR			| _tcscpy	| _tcscat	| _ tcscmp	|
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

BOOLEAN InitWindow(HINSTANCE hInstance, int nCmdShow);	// ��ʼ�������ಢ��������
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// ���ں���

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

// ��ʼ�������ಢ��������
BOOLEAN InitWindow(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	TCHAR szWindowClass[]	= _T("����ʾ��");
	TCHAR szTitle[]			= _T("ӳ��ģʽ�����ʵ��ͼ");

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
		MessageBox(NULL, _T("������ע��ʧ�ܣ�"), _T("����ע��"), NULL);
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
		MessageBox(NULL, _T("��������ʧ�ܣ�"), _T("��������"), NULL);
		return FALSE;
	}
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

// ���ں���
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




















