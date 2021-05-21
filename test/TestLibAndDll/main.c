#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>
#include "../Debug/testLib.h"

#pragma comment(lib,"TestLib.lib")

typedef int(*mulFunc) (int, int);
typedef int(*divFunc) (int, int);

int main(int argc, char* argv[])
{
	int a, b;
	printf("请输入两个数：");

	scanf("%d%d", &a, &b);
	printf("%d+%d=%d\n", a, b, add(a, b));
	printf("%d-%d=%d\n", a, b, sub(a, b));

	HMODULE module = LoadLibrary(L"../Debug/TestDll.dll");

	if (module==NULL)
	{
		printf("调用动态库失败\n");
		return 0;
	}

	mulFunc mul = (mulFunc)GetProcAddress(module, "mul");
	divFunc div = (divFunc)GetProcAddress(module, "div");

	printf("%d*%d=%d\n", a, b, mul(a, b));
	printf("%d/%d=%d\n", a, b, div(a, b));

	getchar();
	return 0;
}
