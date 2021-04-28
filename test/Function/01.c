#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100

typedef unsigned long long int longInt;

int secret_number;

bool is_prime(int n);
longInt recursive(int n);
void guess_number();
void generate_secret_number();
void read_guess();

int main(int argc, char* argv[])
{
	int n;

	printf("������һ������");
	scanf_s("%d", &n);
	if (is_prime(n))
	{
		printf("%d��������\n", n);
	}
	else
	{
		printf("%d����������\n", n);
	}

	printf("%d�Ľ׳��ǣ�%lld\n", n, recursive(n));

	guess_number();
}

/***********************************
 *           �ж�����               *
 ***********************************/
bool is_prime(int n)
{
	if (n <= 1)
	{
		return false;
	}

	for (int divisor = 2; divisor*divisor <= n; divisor++)
	{
		if (n%divisor == 0)
		{
			return false;
		}
	}

	return true;
}

/***********************************
 *         ��һ�����Ľ׳�             *
 ***********************************/
longInt recursive(int n)
{
	return n <= 1 ? 1 : recursive(n - 1) * n;
}

/***********************************
 *             ����                 *
 ***********************************/
void guess_number()
{
	char command;

	printf("������Ϸ����1-100��\n");

	do
	{
		generate_secret_number();
		printf("һ���µ����Ѿ�������\n");
		read_guess();
		printf("�ٴ���Ϸ��(Y/N)");
		scanf_s(" %c", &command);
		printf("\n");
	}
	while (command=='y'|| command=='Y');
}

/***********************************
 *         ����һ���µ���             *
 ***********************************/
void generate_secret_number()
{
	srand((unsigned)time(NULL));
	secret_number = rand() % MAX_NUMBER + 1;
}

/***********************************
 *           ������ʵ��              *
 ***********************************/
void read_guess()
{
	int guess, count = 0;

	while (true)
	{
		printf("������һ������");
		scanf_s("%d", &guess);
		count++;
		if (guess>secret_number)
		{
			printf("���ˣ����������롣\n");
		}
		else if (guess < secret_number)
		{
			printf("С�ˣ����������롣\n");
		}
		else
		{
			printf("���ڵ�%d��Ӯ�ˣ�\n", count);
			return;
		}
	}
}
