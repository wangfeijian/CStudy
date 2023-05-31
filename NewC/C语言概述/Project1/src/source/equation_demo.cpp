#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "../header/equation_demo.h";

int getNumber(char const* str)
{
	int result;
	printf(str);

	int ret = scanf("%d", &result);
	while (0 == ret)
	{
		printf("请输入一个数字，重新");
		printf(str);
		while (getchar() != '\n')
		{
			;
		}
		ret = scanf("%d", &result);
	}

	return result;
}

void clearInputBuffer(void)
{
	while (getchar() != '\n')
	{
		;
	}
}

bool checkContinue(void)
{
	char again;
	printf("是否继续y/n :");

	again = getchar();

	if ('y' == again)
	{
		return true;
	}
	else
	{
		printf("输入的值非y，直接退出！\n");
		return false;
	}
}

void calcAndDisplay(int a, int b, int c)
{
	double temp = b * b - 4 * a * c;
	double x1, x2;

	if (temp > 0)
	{
		x1 = (-b + temp) / (2 * a);
		x2 = (-b - temp) / (2 * a);
		printf("a为%d，b为%d，c为%d的一元二次方程有二个解，X1：%.2f；X2：%.2f;\n", a, b, c, x1, x2);
	}
	else if (temp == 0)
	{
		x1 = x2 = -b / (2 * a);
		printf("a为%d，b为%d，c为%d的一元二次方程有一个解%.2f\n", a, b, c, x1);
	}
	else
	{
		printf("a为%d，b为%d，c为%d的一元二次方程无解\n", a, b, c);
	}
}

void equation(void)
{
	int a, b, c;
	while (true)
	{
		system("cls");
		printf("这是一个计算一元二次方程的程序，根据提示依次输入一元二次方程的三个系数，就可以计算出方程的根\n");
		printf("请依次输入三个系数、a、b、c\n");
		a = getNumber("输入a:");
		b = getNumber("输入b:");
		c = getNumber("输入c:");

		calcAndDisplay(a, b, c);

		clearInputBuffer();
		if (!checkContinue())
		{
			break;
		}
	}
}