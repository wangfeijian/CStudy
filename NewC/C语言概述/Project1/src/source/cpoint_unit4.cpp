#define _CRT_SECURE_NO_WARNINGS

#include "../header/cpoint_unit4.h"
#include "../header/equation_demo.h"

void practice4_1(void)
{
	printf("通过近似值求正整数的平方根\n");

	while (true)
	{

		int num = getNumber("输入Num：");

		double value = selfSqrt(num);

		printf("%d的平方根是%f\n", num, value);

		clearInputBuffer();
		if (!checkContinue())
		{
			break;
		}
	}
}

void practice4_3(void)
{
	printf("请输入三角形的三条边\n");

	int a = getNumber("输入第一条边:");
	int b = getNumber("输入第二条边:");
	int c = getNumber("输入第三条边:");

	if ((a + b) > c && (a + c) > b && (b + c) > a)
	{
		if (a == b && b == c)
		{
			printf("三条边长分别为%d %d %d的直线可以能够成一个等边三角形\n", a, b, c);
		}
		else if (a == b || b == c || a == c)
		{
			printf("三条边长分别为%d %d %d的直线可以能够成一个等腰三角形\n", a, b, c);
		}
		else
		{
			printf("三条边长分别为%d %d %d的直线可以能够成一个不等边三角形\n", a, b, c);
		}
	}
	else
	{
		printf("三条边长分别为%d %d %d的直线不能够成三角形\n", a, b, c);
	}
}