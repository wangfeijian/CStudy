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

	printf("请输入一个数：");
	scanf_s("%d", &n);
	if (is_prime(n))
	{
		printf("%d是素数。\n", n);
	}
	else
	{
		printf("%d不是素数。\n", n);
	}

	printf("%d的阶乘是：%lld\n", n, recursive(n));

	guess_number();
}

/***********************************
 *           判断素数               *
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
 *         求一个数的阶乘             *
 ***********************************/
longInt recursive(int n)
{
	return n <= 1 ? 1 : recursive(n - 1) * n;
}

/***********************************
 *             猜数                 *
 ***********************************/
void guess_number()
{
	char command;

	printf("猜数游戏，猜1-100。\n");

	do
	{
		generate_secret_number();
		printf("一个新的数已经产生。\n");
		read_guess();
		printf("再次游戏？(Y/N)");
		scanf_s(" %c", &command);
		printf("\n");
	}
	while (command=='y'|| command=='Y');
}

/***********************************
 *         生成一个猜的数             *
 ***********************************/
void generate_secret_number()
{
	srand((unsigned)time(NULL));
	secret_number = rand() % MAX_NUMBER + 1;
}

/***********************************
 *           猜数的实现              *
 ***********************************/
void read_guess()
{
	int guess, count = 0;

	while (true)
	{
		printf("请输入一个数：");
		scanf_s("%d", &guess);
		count++;
		if (guess>secret_number)
		{
			printf("大了，请重新输入。\n");
		}
		else if (guess < secret_number)
		{
			printf("小了，请重新输入。\n");
		}
		else
		{
			printf("你在第%d次赢了！\n", count);
			return;
		}
	}
}
