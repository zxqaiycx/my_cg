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
	# C++�е��������
	������������Ʒ�����ȫ�¸���ࡢ��װ��encapsulation����
	�̳У�inheritance���Ͷ�̬��polymorphism���ȡ�

	## ��
	һ���ຬ�������֣�
	* ˽�У�private��:��Ա��������������ֻ�ܱ�����ĳ�Ա�������ʣ�
	* ������protected������Ա���Ա������������ĳ�Ա�������ʣ�������ļ̳У�
	* ������public�����������ֵĳ�Ա���Ա���������ĺ������ʣ��������ⲿ�Ľӿڡ�

	C++��ͨ��Ҳ����ĳ�Ա������Ϊ��ķ�������Ա������ԭ��һ������Ķ�����������
	�����ľ���ʵ�֣���������Ķ����ڲ���ɣ���ʱҲ��Ϊ���������������Ҳ��������Ķ���֮����У�
	�����ľ���ʵ�ּȿ��Ժ���Ķ������һ��Դ�ļ��У�Ҳ���Է��ڲ�ͬ��Դ�ļ��С�
	�����ľ���ʵ������ͨ������ʵ�����в�ͬ����������Ķ���������ⲿʵ�֣����ڶ��巽��ʱ���������
	���ڷ�����֮ǰ���м����������������::)������

	��Ҳ����Ƕ��������

	## ����
	C++�������ַ�ʽ������Ķ���
	* �ڶ������ͬʱֱ�Ӷ�����Ķ���
	* �ڶ�����֮���ٶ�����Ķ���

	## ��������
	����������ָ�����������ڵĳ�Ա���������ú����ĺ�������������ڡ�
	���������ڵ���ʱ����һ��ĺ���Ҫתȥִ�б����ú����ĺ����壬ִ����ɺ���ת�ص��ú�������
	ִ��������䣬�����ڵ��ú�����������������Ĵ������滻������������������ٶȡ�
	�������������Ҫ�ǽ�����������Ч�����⡣
	ע�⣬��������һ��Ҫ�ڵ���֮ǰ���壬�������������޷��ݹ���á�
	C++��ʹ���������ַ�ʽ�����������������
	* ������ⲿ����ʱ���ѹؼ��ּ��غ�������֮ǰ��
	```
	class Angle {
	public:
		explicit Angle(const double xx) : _value(xx) {}
		void SetValue(double);
	private:
		double _value;
	};
	inline void Angle::SetValue(double x)
	{
		_value = x;
	}
	```
	* �Ѻ���ԭ�������ͷ����Ķ���ϲ��������ඨ���С�
	```
	class Angle {
	public:
		explicit Angle(const double xx) : _value(xx) {}
		void SetValue(double x) { _value = x }
	private:
		double _value;
	};
	```
*/
/*
	# ���캯������������
	## ���캯����Constructor��
	* ���캯����û�в��������ԣ�������û�з���ֵ��
	* ���û�и��ඨ�幹�캯��������ϵͳ��Ϊ������һ��ȱʡ�Ĺ��캯������ÿ��ʵ��������ʼ��Ϊ0����
	* ���캯��������ȱʡ������
	* ����û�в����Ĺ��캯������ȱʡ�����Ĺ��캯��ʱ���п��ܲ��������ԡ�

	## ����������Destructor��
	* ��������ǰ���~��
	* ��������û�в�����û�з���ֵ��Ҳ�������أ�һ������ֻ��һ������������
	* �������������ͷŷ����������ڴ�ռ䡣
	* ����������ȱʡ������������������Ҫ��

	# ����
	## ��������
	��������ʱ��Ҫ�����Ĳ���������������Ͳ�ͬ��

	## ����������
	* ���������Ϊ��ĳ�Ա��������Ԫ������
	* һ�㵥Ŀ���������Ϊ��Ա������˫Ŀ���������Ϊ��Ԫ��������ֵ�����=�������Ϊ��Ա������
	* �±������[]����1��1��������������������()��

	# ��Ԫ
	���ⲿ�ĺ�������������з��ʸ����˽�в��ֵ���Ȩ��
	* ��Ԫ������������ĳ�Ա�����������ڲ��������ⲿ���壻���Է�����Ĺ��в��ֻ�˽�в��֡�
	* ��Ԫ�ࣺ��Ԫ���ÿһ����Ա����������һ�������Ԫ������
	* ��Ԫ��ϵ���ܱ��̳С�

	# thisָ��
	* thisָ����ָ��һ����Ķ���ĵ�ַ��
	* this��һ������ָ�룬��������ÿ����ĳ�Ա�����С�
	* `this->member`
	* һ��ָ��������ָ�룺`Class *ClassA = new ClassA`

	# 
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
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// ע������ת����
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