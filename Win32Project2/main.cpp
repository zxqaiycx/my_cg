// ���ߣ���
// ��Դ�����ӻ���̿μ�
// ˵��������������˵������WindowsӦ�ó���ķ���������

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
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szClassName;

	// ע�ᴰ����
	if (!RegisterClass(&wc))
	{
		MessageBeep(0);
		return FALSE;
	}

	// ��������
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
	// ��ʾ����
	ShowWindow(hWnd, nCmdShow);
	// �����û���

	// ��Ϣѭ��
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