#define _CRT_SECURE_NO_WARNINGS 1

#include "testDll.h"

DLLAPI int mul(int a, int b)
{
	return a * b;
}

DLLAPI int div(int a, int b)
{
	return a / b;
}
