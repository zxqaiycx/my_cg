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
	# C++中的类与对象
	面向对象程序设计方法的全新概念：类、封装（encapsulation）、
	继承（inheritance）和多态（polymorphism）等。

	## 类
	一个类含有三部分：
	* 私有（private）:成员（变量、函数）只能被本类的成员函数访问；
	* 保护（protected）：成员可以被本类和派生类的成员函数访问，用于类的继承；
	* 公共（public）：公共部分的成员可以被本类以外的函数访问，是类与外部的接口。

	C++中通常也把类的成员函数称为类的方法。成员函数的原型一般在类的定义中声明。
	方法的具体实现，可以在类的定义内部完成（有时也称为类的内联函数），也可以在类的定义之外进行，
	方法的具体实现既可以和类的定义放在一个源文件中，也可以放在不同的源文件中。
	方法的具体实现与普通函数的实现略有不同，如果方法的定义在类的外部实现，则在定义方法时必须把类名
	放在方法名之前，中间用作用域运算符（::)隔开。

	类也可以嵌套声明。

	## 对象
	C++中有两种方式定义类的对象：
	* 在定义类的同时直接定义类的对象；
	* 在定义类之后再定义类的对象。

	## 内联函数
	内联函数是指定义在类体内的成员函数，即该函数的函数体放在类体内。
	内联函数在调用时不像一般的函数要转去执行被调用函数的函数体，执行完成后再转回调用函数处，
	执行其后的语句，而是在调用函数处用内联函数体的代码来替换，这样将会提高运行速度。
	因此内联函数主要是解决程序的运行效率问题。
	注意，内联函数一定要在调用之前定义，并且内联函数无法递归调用。
	C++中使用下面两种方式定义类的内联函数：
	* 在类的外部定义时，把关键字加载函数定义之前。
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
	* 把函数原型声明和方法的定义合并，放入类定义中。
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
	# 构造函数和析构函数
	## 构造函数（Constructor）
	* 构造函数有没有参数都可以，但不能没有返回值。
	* 如果没有给类定义构造函数，编译系统将为类生成一个缺省的构造函数（将每个实例变量初始化为0）。
	* 构造函数可以有缺省参数。
	* 重载没有参数的构造函数和有缺省参数的构造函数时，有可能产生二义性。

	## 析构函数（Destructor）
	* 析构函数前面加~。
	* 析构函数没有参数，没有返回值，也不能重载，一个类中只有一个析构函数。
	* 析构函数用于释放分配给对象的内存空间。
	* 大多数情况，缺省的析构函数就能满足要求。

	# 重载
	## 函数重载
	函数重载时，要求函数的参数个数或参数类型不同。

	## 操作符重载
	* 运算符重载为类的成员函数或友元函数。
	* 一般单目运算符重载为成员函数，双目运算符重载为友元函数。赋值运算符=最好重载为成员函数。
	* 下标运算符[]、增1减1运算符、函数调用运算符()。

	# 友元
	类外部的函数或其他类具有访问该类的私有部分的特权。
	* 友元函数：不是类的成员函数，在类内部声明，外部定义；可以放在类的公有部分或私有部分。
	* 友元类：友元类的每一个成员函数都是另一个类的友元函数。
	* 友元关系不能被继承。

	# this指针
	* this指针是指向一个类的对象的地址。
	* this是一种隐含指针，它隐含于每个类的成员函数中。
	* `this->member`
	* 一般指向类对象的指针：`Class *ClassA = new ClassA`

	# 
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
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 注意类型转换；
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