#ifndef TESTDLL
#define TESTDLL

#ifdef DLLAPI
#define DLLAPI __declspec(dllexport)
#else
#define DLLAPI __declspec(dllimport)
#endif

//�������C++������Ҫ��ǰ�����extern "C"

DLLAPI int mul(int a, int b);

DLLAPI int div(int a, int b);
#endif