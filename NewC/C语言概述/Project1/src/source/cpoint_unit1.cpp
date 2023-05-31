#define _CRT_SECURE_NO_WARNINGS

#include "../header/cpoint_unit1.h"
#include "../header/equation_demo.h"

void testRearrange(void)
{
	int nColumns;
	int columns[MAX_COLS];
	char inputs[MAX_INPUT];
	char outputs[MAX_INPUT];

	system("cls");

	printf("这是一个通过输入列标号，通过这些标号，打印输入的字符串列标号之间的字符\n");
	printf("输入的串列标号以-1结束\n");
	printf("例如，0 3 10 12 -1表示第2列到第3列，第10列到第12列的内容被打印\n");

	printf("请输入规则：");
	nColumns = readColumnNumbers(columns, MAX_COLS);

	while (true)
	{
		printf("请输入原始字符:");
		gets_s(inputs);
		printf("Original input : %s\n", inputs);
		rearrange(outputs, inputs, nColumns, columns);
		printf("Rearranged line: %s\n", outputs);

		if (!checkContinue())
		{
			break;
		}
		clearInputBuffer();
	}
}

int readColumnNumbers(int columns[], int max)
{
	int num = 0;
	int ch;

	while (num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0)
	{
		num++;
	}

	if (num % 2 != 0)
	{
		puts("Last column number is not paired.");
		exit(EXIT_FAILURE);
	}

	while ((ch = getchar()) != EOF && ch != '\n')
	{
		;
	}

	return num;
}

void rearrange(char* output, char const* input, int nColumns, int const columns[])
{
	int col;
	int outputCol;
	int len;

	len = strlen(input);
	outputCol = 0;

	for (col = 0; col < nColumns; col += 2)
	{
		int nchars = columns[col + 1] - columns[col] + 1;

		if (columns[col] >= len || outputCol == MAX_INPUT - 1)
		{
			break;
		}

		if (outputCol + nchars > MAX_INPUT - 1)
		{
			nchars = MAX_INPUT - outputCol - 1;
		}

		strncpy(output + outputCol, input + columns[col], nchars);
		outputCol += nchars;
	}

	output[outputCol] = '\0';
}

void practice2(void)
{
	int ch;
	int line = 0;
	int atBeginning = 1;

	while ((ch = getchar()) != EOF)
	{
		if (atBeginning == 1)
		{
			atBeginning = 0;
			line += 1;
			printf("%d ", line);
		}

		putchar(ch);
		if (ch == '\n')
		{
			atBeginning = 1;
		}
	}
}

void practice3(void)
{
	int ch;
	int atBeginning = 1;
	signed char num;

	while ((ch = getchar()) != EOF)
	{
		if (atBeginning == 1)
		{
			atBeginning = 0;
			num = -1;
		}
		num += ch;
		putchar(ch);
		if (ch == '\n')
		{
			atBeginning = 1;
			printf("%d\n", num);
		}
	}
}

void practice4(void)
{
	char inputs[MAX_INPUT];
	char outputs[MAX_INPUT];
	int maxLen = 0;
	int maxLine;
	int line = 0;

	printf("请输入要比较多少行数据：");
	scanf("%d", &maxLine);
	clearInputBuffer();

	while (true)
	{
		printf("请输入第%d行数据：", ++line);
		gets_s(inputs);
		int currentLen = strlen(inputs);

		if (currentLen > maxLen)
		{
			maxLen = currentLen;
			strcpy(outputs, inputs);
		}

		if (line >= maxLine)
		{
			break;
		}
	}

	printf("输入最长的一行是：%s\n", outputs);
}

void practice5(char* output, char const* input, int nColumns, int const columns[])
{
	int col;
	int outputCol;
	int len;

	len = strlen(input);
	outputCol = 0;

	for (col = 0; col < nColumns; col += 2)
	{
		int maxNum = (columns[col + 1] - columns[col]) >= 0 ? columns[col] : columns[col + 1];
		int nchars = abs(columns[col + 1] - columns[col]) + 1;

		if (maxNum >= len || outputCol == MAX_INPUT - 1)
		{
			break;
		}

		if (outputCol + nchars > MAX_INPUT - 1)
		{
			nchars = MAX_INPUT - outputCol - 1;
		}

		strncpy(output + outputCol, input + maxNum, nchars);
		outputCol += nchars;
	}

	output[outputCol] = '\0';
}

void testPractice5(void)
{
	int nColumns;
	int columns[MAX_COLS];
	char inputs[MAX_INPUT];
	char outputs[MAX_INPUT];

	system("cls");

	printf("这是一个通过输入列标号，通过这些标号，打印输入的字符串列标号之间的字符\n");
	printf("输入的串列标号以-1结束\n");
	printf("例如，0 3 10 12 -1表示第2列到第3列，第10列到第12列的内容被打印\n");

	printf("请输入规则：");
	nColumns = readColumnNumbers(columns, MAX_COLS);

	while (true)
	{
		printf("请输入原始字符:");
		gets_s(inputs);
		printf("Original input : %s\n", inputs);
		practice5(outputs, inputs, nColumns, columns);
		printf("Rearranged line: %s\n", outputs);

		if (!checkContinue())
		{
			break;
		}
		clearInputBuffer();
	}
}

int practice6_1(int columns[], int max)
{
	int num = 0;
	int ch;

	while (num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0)
	{
		num++;
	}

	while ((ch = getchar()) != EOF && ch != '\n')
	{
		;
	}

	return num;
}

void practice6_2(char* output, char const* input, int nColumns, int const columns[])
{
	int col;
	int outputCol;
	int len;

	len = strlen(input);
	outputCol = 0;

	for (col = 0; col < nColumns; col += 2)
	{
		int minNum = (col + 1) == nColumns ? len : columns[col + 1];
		int maxNum = (minNum - columns[col]) >= 0 ? columns[col] : minNum;
		int nchars = abs(minNum - columns[col]) + 1;

		if (maxNum >= len || outputCol == MAX_INPUT - 1)
		{
			break;
		}

		if (outputCol + nchars > MAX_INPUT - 1)
		{
			nchars = MAX_INPUT - outputCol - 1;
		}

		strncpy(output + outputCol, input + maxNum, nchars);
		outputCol += nchars;
	}

	output[outputCol] = '\0';
}

void testPractice6(void)
{
	int nColumns;
	int columns[MAX_COLS];
	char inputs[MAX_INPUT];
	char outputs[MAX_INPUT];

	system("cls");

	printf("这是一个通过输入列标号，通过这些标号，打印输入的字符串列标号之间的字符\n");
	printf("输入的串列标号以-1结束\n");
	printf("例如，0 3 10 12 -1表示第2列到第3列，第10列到第12列的内容被打印\n");

	printf("请输入规则：");
	nColumns = practice6_1(columns, MAX_COLS);

	while (true)
	{
		printf("请输入原始字符:");
		gets_s(inputs);
		printf("Original input : %s\n", inputs);
		practice6_2(outputs, inputs, nColumns, columns);
		printf("Rearranged line: %s\n", outputs);

		if (!checkContinue())
		{
			break;
		}
		clearInputBuffer();
	}
}