// ���ߣ���Тǫ
// ��Դ�����ӻ���̿μ�
// ˵��������������˵������WindowsӦ�ó���ķ���������

/*
	| ������������			| ������λ	| ֵ��		|	
	| --------------------- | --------- | --------- |
	| (signed) char			| 8			|			|
	| unsigned char			| 8			|			|
	| (signed) int			| 16		|			|
	| unsigned int			| 16		|			|
	| (signed) short int	| 16		|			|
	| unsigned short int	| 16		|			|
	| (signed) long int		| 32		|			|
	| unsigned long int		| 32		|			|
	| float					| 32		| 7λ��Чλ	|
	| double				| 64		| 15λ��Чλ	|
	| long double			| 89		| 19λ��Чλ	|
*/
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
/*
	
*/

#include <Windows.h>

// ������ǰ������
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // ���ں���

int WINAPI WinMain(HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPSTR lpszCmdLine,
					int nCmdShow)
{
	HWND hWnd;
	MSG msg;
	LPCWSTR szClassName = TEXT("����");		// ��������
	LPCWSTR szTitle = TEXT("WindowTitle");	// ���ڱ�����

	// ��ʼ��������
	WNDCLASS wc;
	wc.style = 0;					// ��������ΪĬ������
	wc.lpfnWndProc = WndProc;		// ���崰�ڴ�����
	wc.cbClsExtra = 0;				// ����������չ
	wc.cbWndExtra = 0;				// ����ʵ������չ
	wc.hInstance = hInstance;		// ��ǰʵ�����
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// ���ڵ���С��ͼ��ΪĬ��ͼ��
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// ���ڲ��ü�ͷ���
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// ע������ת�������ڱ���Ϊ��ɫ��BLACK_BRUSHҲ����
	wc.lpszMenuName = NULL;			// �������޲˵�
	wc.lpszClassName = szClassName;	// ��������Ϊǰ�������ڡ�

	// ע�ᴰ����
	if (!RegisterClass(&wc))		// ���ע��ʧ���򷢳�����
	{
		MessageBeep(0);
		return FALSE;
	}

	// ��������
	hWnd = CreateWindow(szClassName,		// ��������
						szTitle,			// ����ʵ���ı�����
						WS_OVERLAPPEDWINDOW,// ���ڵķ��
						CW_USEDEFAULT,		// �������Ͻ�ͼ��ΪĬ��ֵ
						CW_USEDEFAULT,
						CW_USEDEFAULT,		// ���ڵĿ��ΪĬ��ֵ
						CW_USEDEFAULT,
						NULL,				// �˴����޸�����
						NULL,				// �˴��������˵�
						hInstance,			// �����˴��ڵ�Ӧ�ó���ĵ�ǰ���
						NULL);				// ��ʹ�ø�ֵ
	// ��ʾ����
	ShowWindow(hWnd, nCmdShow);
	// �����û���

	// ��Ϣѭ��
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;	// ��Ϣѭ��������������ֹʱ����Ϣ����ϵͳ
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