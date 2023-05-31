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
		printf("������һ�����֣�����");
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
	printf("�Ƿ����y/n :");

	again = getchar();

	if ('y' == again)
	{
		return true;
	}
	else
	{
		printf("�����ֵ��y��ֱ���˳���\n");
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
		printf("aΪ%d��bΪ%d��cΪ%d��һԪ���η����ж����⣬X1��%.2f��X2��%.2f;\n", a, b, c, x1, x2);
	}
	else if (temp == 0)
	{
		x1 = x2 = -b / (2 * a);
		printf("aΪ%d��bΪ%d��cΪ%d��һԪ���η�����һ����%.2f\n", a, b, c, x1);
	}
	else
	{
		printf("aΪ%d��bΪ%d��cΪ%d��һԪ���η����޽�\n", a, b, c);
	}
}

void equation(void)
{
	int a, b, c;
	while (true)
	{
		system("cls");
		printf("����һ������һԪ���η��̵ĳ��򣬸�����ʾ��������һԪ���η��̵�����ϵ�����Ϳ��Լ�������̵ĸ�\n");
		printf("��������������ϵ����a��b��c\n");
		a = getNumber("����a:");
		b = getNumber("����b:");
		c = getNumber("����c:");

		calcAndDisplay(a, b, c);

		clearInputBuffer();
		if (!checkContinue())
		{
			break;
		}
	}
}