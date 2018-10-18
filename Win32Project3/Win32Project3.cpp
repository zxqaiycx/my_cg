// ���ߣ���Тǫ
// ��Դ�����ӻ���̿μ�
// ˵��������������˵������WindowsӦ�ó���ķ���������


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


#include <Windows.h>
#include <tchar.h>		// _T()

// ������ǰ������
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // ���ں���

// ��ں���
int WINAPI WinMain(HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPSTR lpszCmdLine,
					int nCmdShow)
{
	HWND hWnd;
	MSG msg;
	TCHAR szWindowClass[] = L"����ʾ��";
	TCHAR szTitle[] = L"My Window";
	//LPCWSTR szWindowClass = TEXT("����");		// ��������
	//LPCWSTR szTitle = TEXT("WindowTitle");	// ���ڱ�����

	// ���³�ʼ��������
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);									// ������Ĵ�С
	wcex.style = CS_HREDRAW | CS_VREDRAW;		// ��������												// ��������ΪĬ������
	wcex.lpfnWndProc = WndProc;											// ���崰�ڴ�����
	wcex.cbClsExtra = 0;												// ����������չ
	wcex.cbWndExtra = 0;												// ����ʵ������չ
	wcex.hInstance = hInstance;											// ��ǰʵ�����
	//wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));	// ����ͼ��ΪĬ��ͼ��
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);							// ���ڲ��ü�ͷ���
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);			// ע������ת����
	wcex.lpszMenuName = NULL;											// �������޲˵�
	wcex.lpszClassName = szWindowClass;									// ��������Ϊǰ��������ʾ����
	//wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hIconSm = LoadIcon(hInstance, IDI_APPLICATION);			//����Сͼ��ΪĬ��ͼ��

	// ����ע�ᴰ����
	if (!RegisterClassEx(&wcex))		// ���ע��ʧ���򷢳�����
	{
		MessageBox(NULL, _T("������ע��ʧ�ܣ�"), _T("����ע��"), NULL);
		return 1;
	}
	//if (!RegisterClass(&wcex))		// ���ע��ʧ���򷢳�����
	//{
	//	MessageBeep(0);
	//	return FALSE;
	//}

	// ���´�������
	hWnd = CreateWindow(
		szWindowClass,					// ��������
		szTitle,						// ����ʵ���ı�����
		WS_OVERLAPPEDWINDOW,			// ���ڵķ��
		CW_USEDEFAULT, CW_USEDEFAULT,	// �������Ͻ�����ΪĬ��ֵ
		CW_USEDEFAULT, CW_USEDEFAULT,	// ���ڵĿ��ΪĬ��ֵ
		NULL,							// �˴����޸�����
		NULL,							// �˴��������˵�
		hInstance,						// �����˴��ڵ�Ӧ�ó���ĵ�ǰ���
		NULL);							// ��ʹ�ø�ֵ

	if (!hWnd)							// ��������ʧ���򷢳�����
	{
		MessageBox(NULL, _T("��������ʧ�ܣ�"), _T("��������"), NULL);
		return 1;
	}
	ShowWindow(hWnd, nCmdShow);			// ��ʾ����
	UpdateWindow(hWnd);					// �����û���

	// ��Ϣѭ��
	while (GetMessage(&msg, NULL, 0, 0))// ����Ϣ���ж�ȡ��Ϣ������MSG�ṹ��
	{
		TranslateMessage(&msg);			// ����Ϣ�������ת��Ϊ�ַ���Ϣ
		DispatchMessage(&msg);			// ������ָ�����Ϣ���͵�ָ���Ĵ��ں���
	}									// GetMessage������ֵ��ѭ������
	
	return (int)msg.wParam;				// ��Ϣѭ��������������ֹʱ����Ϣ����ϵͳ
}

// ���¶��崰�ں���
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