/*#include <stdio.h>
typedef _Bool Sex;

#define N 5

void show();

int main(int argc, char* argv[])
{
	show();
	int height = 180;
	int weight;
	char c = 65;
	char d = 97;
	weight = 160;
	Sex a = 0;
	Sex b = 1;

	printf("我的体重是：%d斤\n体重和身高的比是：%d\n无意义的值：%d\n", weight, height / weight);

	for (int i = 0; i < 26; i++)
	{
		if (i % 7 == 0)
		{
			putchar('\n');
		}
		putchar(c);
		putchar(d);
		putchar('\t');
		c++;
		d++;
	}
	printf("\n");

	do
	{
		c = getchar();
	} while (c != '\n');

	if (a)
	{
		printf("不输出\n");
	}

	if (b)
	{
		printf("输出\n");
	}
	return 0;
}

void show()
{
	int a[N] = { 1,2,3,4,5 };

	for (int* p = a; p < a + N; p++)
	{
		printf("%p:%d\n", p, *p);
	}

}*/
