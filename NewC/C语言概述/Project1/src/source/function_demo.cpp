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
	printf("��1-%d��Χ�ڣ����е��������£�\n", num);

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

	printf("��1-%d��Χ��, һ����%d������\n", num, count);
}

void functionTest(void)
{
	int num;
	while (true)
	{
		system("cls");
		printf("����һ����һ������Χ�����������ĳ��򣬸�����ʾ��������һ�������Ϳ��Լ����ڸ�����Χ�����е�����\n");
		printf("������һ����\n");
		num = getNumber("����:");

		showAllPrimersOfRanger(num);

		clearInputBuffer();

		if (!checkContinue())
		{
			break;
		}
	}
}