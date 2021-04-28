#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N 5
#define ARRAY_LENGTH(a) (int)sizeof(a)/sizeof(a[0])
#define INITIAL_BALANCE 100.00
#define NUM_SUIT 4
#define NUM_RANK 13

void reverse(void);
void checkRepeatedNumber(void);
void checkRepeatedNumberAndCaculateRepeatNumber(void);
void showRate(void);
void licensing(void);


int main(int argc, char* argv[])
{
	licensing();
	showRate();
	int a[3] = { 0 };
	printf("%d", ARRAY_LENGTH(a));
	reverse();
	checkRepeatedNumber();
	checkRepeatedNumberAndCaculateRepeatNumber();
	return 0;
}


/***********************************
 *      输入一组数字，输出反转         *
 ***********************************/
void reverse(void)
{
	int a[N];
	int* p;

	printf("输入%d个数字：", N);
	for (p = &a[0]; p < &a[N]; p++)
	{
		 scanf_s("%d", p);
	}

	printf("反转后的数字：");
	for (p = &a[N - 1]; p >= &a[0]; p--)
	{
		printf("%d ", *p);
	}
	printf("\n");
}

/***********************************
 *      检查输入的数字是否重复          *
 ***********************************/
void checkRepeatedNumber(void)
{
	bool digit_seen[10] = { false };
	unsigned int n;

	printf("请输入一个数字：");
	 scanf_s("%u", &n);

	while (n > 0)
	{
		int digit = n % 10;
		n /= 10;
		if (digit_seen[digit] == true)
		{
			break;
		}
		digit_seen[digit] = true;
	}

	if (n > 0)
	{
		printf("输入的数字存在重复。\n");
	}
	else
	{
		printf("输入的数字没有重复。\n");
	}
}

/***********************************
 *      检查输入的数字重复个数          *
 ***********************************/
void checkRepeatedNumberAndCaculateRepeatNumber(void)
{
	int digit_seen[10] = { 0 };
	int n;

	printf("请输入一个数字：");
	 scanf_s("%d", &n);

	while (n > 0)
	{
		int digit = n % 10;
		n /= 10;
		digit_seen[digit] += 1;
	}

	for (int i = 0; i < ARRAY_LENGTH(digit_seen); i++)
	{
		printf("%d:%d\n", i, digit_seen[i]);
	}
}

/***********************************
 *           显示利率               *
 ***********************************/
void showRate(void)
{
	int rate;
	int year;
	double value[5];

	printf("输入利率：");
	 scanf_s("%d", &rate);
	printf("输入年份：");
	 scanf_s("%d", &year);

	printf("\nYears");
	for (int i = 0; i < ARRAY_LENGTH(value); i++)
	{
		printf("%7d%%", rate + i);
		value[i] = INITIAL_BALANCE;
	}
	printf("\n");

	for (int i = 0; i < year; i++)
	{
		printf("%3d    ", i);
		for (int j = 0; j < ARRAY_LENGTH(value); j++)
		{
			value[j] += value[j] * (rate + j) / 100;
			printf("%8.2f", value[j]);
		}
		printf("\n");
	}
}

/***********************************
 *             发牌                 *
 ***********************************/
void licensing(void)
{
	int suit, rank, num_cards;

	const char suit_code[] = { 'H','D','C','S' };
	const char rank_code[] = { '2','3','4','5','6','7','8','9','T','J','Q','K','A' };
	bool in_hand[NUM_SUIT][NUM_RANK] = { false };

	srand((unsigned)time(NULL));

	printf("输入在手中的牌的数量：");
	 scanf_s("%d", &num_cards);

	printf("你的手牌：");

	while (num_cards > 0)
	{
		suit = rand() % NUM_SUIT;
		rank = rand() % NUM_RANK;
		if (!in_hand[suit][rank])
		{
			in_hand[suit][rank] = true;
			num_cards--;
			printf("%c%c    ", suit_code[suit], rank_code[rank]);
		}
	}
	printf("\n");
}