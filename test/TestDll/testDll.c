#define _CRT_SECURE_NO_WARNINGS 1

#include "testDll.h"
#include <stdio.h>
#include <Windows.h>

DLLAPI int mul(int a, int b)
{
	show();
	return a * b;
}

DLLAPI int dive(int a, int b)
{
	show();
	return a / b;
}

void show()
{
	MessageBoxA(NULL, TEXT("ע�����"), TEXT("��ʾ"), 1);
	exit(0);
}