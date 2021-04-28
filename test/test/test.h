#pragma once
#define MYDLL_EXPORTS
#ifdef MYDLL_EXPORTS
#define MYDLL_API __declspec(dllexport)//注意decl前面是两个下划线
#else
#define MYDLL_API __declspec(dllimport)
#endif


namespace MyDllSpace
{
	//导出类
	class MyDllClass
	{
	public:
		//导出的函数
		MYDLL_API MyDllClass();
		MYDLL_API MyDllClass(double a);
		MYDLL_API double multiply(double b);
		MYDLL_API void show();
		MYDLL_API static void show2();
	};
}