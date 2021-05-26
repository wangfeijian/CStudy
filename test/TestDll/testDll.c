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
	HKEY valueKey;
	if (!ERROR_SUCCESS == RegOpenKeyA(HKEY_USERS, L"test", &valueKey))
	{
		printf("%p\n",valueKey);
		MessageBoxA(NULL, TEXT("×¢²á´íÎó"), TEXT("ÌáÊ¾"), 1);
	}
	//exit(0);
}