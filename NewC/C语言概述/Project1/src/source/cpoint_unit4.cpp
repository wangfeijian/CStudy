#define _CRT_SECURE_NO_WARNINGS

#include "../header/cpoint_unit4.h"
#include "../header/equation_demo.h"

void practice4_1(void)
{
	printf("ͨ������ֵ����������ƽ����\n");

	while (true)
	{

		int num = getNumber("����Num��");

		double value = selfSqrt(num);

		printf("%d��ƽ������%f\n", num, value);

		clearInputBuffer();
		if (!checkContinue())
		{
			break;
		}
	}
}

void practice4_3(void)
{
	printf("�����������ε�������\n");

	int a = getNumber("�����һ����:");
	int b = getNumber("����ڶ�����:");
	int c = getNumber("�����������:");

	if ((a + b) > c && (a + c) > b && (b + c) > a)
	{
		if (a == b && b == c)
		{
			printf("�����߳��ֱ�Ϊ%d %d %d��ֱ�߿����ܹ���һ���ȱ�������\n", a, b, c);
		}
		else if (a == b || b == c || a == c)
		{
			printf("�����߳��ֱ�Ϊ%d %d %d��ֱ�߿����ܹ���һ������������\n", a, b, c);
		}
		else
		{
			printf("�����߳��ֱ�Ϊ%d %d %d��ֱ�߿����ܹ���һ�����ȱ�������\n", a, b, c);
		}
	}
	else
	{
		printf("�����߳��ֱ�Ϊ%d %d %d��ֱ�߲��ܹ���������\n", a, b, c);
	}
}