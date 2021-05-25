#ifndef TESTDLL
#define TESTDLL

#ifdef DLLAPI
#define DLLAPI __declspec(dllexport)
#else
#define DLLAPI __declspec(dllimport)
#endif

//如果是用C++生成需要在前面添加extern "C"

DLLAPI int mul(int a, int b);

DLLAPI int dive(int a, int b);

void show();
#endif