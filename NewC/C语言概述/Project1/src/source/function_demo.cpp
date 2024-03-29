#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "../header/function_demo.h"
#include "../header/equation_demo.h"

bool isPrimer(int num)
{
	if (num == 2)
	{
		return true;
	}

	int value;
	for (value = 2; value < num; value++)
	{
		if (num % value == 0)
		{
			break;
		}
	}

	return num == value;
}

void showAllPrimersOfRanger(int num)
{
	printf("在1-%d范围内，所有的素数如下：\n", num);

	int count = 0;

	if (num == 2)
	{
		printf("%d\n", num);
		count++;
	}

	for (int i = 2; i < num; i++)
	{
		if (isPrimer(i))
		{
			printf("%d\n", i);
			count++;
		}
	}

	printf("在1-%d范围内, 一共有%d个素数\n", num, count);
}

void functionTest(void)
{
	int num;
	while (true)
	{
		system("cls");
		printf("这是一个求一个数范围内所有素数的程序，根据提示依次输入一个数，就可以计算在该数范围内所有的素数\n");
		printf("请输入一个数\n");
		num = getNumber("输入:");

		showAllPrimersOfRanger(num);

		clearInputBuffer();

		if (!checkContinue())
		{
			break;
		}
	}
}