#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
#define ARRAY_LENGTH(n) (int)sizeof(n)/sizeof(n[0])

void max_min(int a[], int len, int *max, int *min);
void reverse(int a[], int len);

int main(int argc, char* argv[])
{
	int a[SIZE];

	int max, min;

	printf("����5����:");
	for (int i = 0; i < ARRAY_LENGTH(a); i++)
	{
		scanf_s("%d", &a[i]);
	}
	max_min(a, ARRAY_LENGTH(a), &max, &min);

	reverse(a, ARRAY_LENGTH(a));

	printf("���ֵ��%d��\n", max);
	printf("��Сֵ��%d��\n", min);
	system("pause");
}

void max_min(int a[], int len, int* max, int* min)
{
	*max = *min = a[0];

	for (int i = 0; i < len; i++)
	{
		if (a[i] > *max)
		{
			*max = a[i];
		}
		else if (a[i] < *min)
		{
			*min = a[i];
		}
	}
}

void reverse(int a[], int len)
{
	int *p;

	for (p = a + len - 1; p >= a; p--)
	{
		printf("%d\n", *p);
	}
}
