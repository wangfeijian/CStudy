#pragma once
#define MYDLL_EXPORTS
#ifdef MYDLL_EXPORTS
#define MYDLL_API __declspec(dllexport)//ע��declǰ���������»���
#else
#define MYDLL_API __declspec(dllimport)
#endif


namespace MyDllSpace
{
	//������
	class MyDllClass
	{
	public:
		//�����ĺ���
		MYDLL_API MyDllClass();
		MYDLL_API MyDllClass(double a);
		MYDLL_API double multiply(double b);
		MYDLL_API void show();
		MYDLL_API static void show2();
	};
}