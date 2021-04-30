#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 100

int read_line(char str[], int read_num);
void reminder_test();
char digit_to_hex_char(int digit);
void do_work();
int read_line(char str[], int read_num);
void str_process();
void nine_point();
void show(int x, int y, int z);

int main(int argc, char* argv[])
{
	nine_point();
	reminder_test();

	str_process();

	char strInput[20];
	read_line(strInput, 20);
	printf("%s\n", strInput);
	do_work();

	getchar();
}

char digit_to_hex_char(int digit)
{
	return "0123456789ABCDEF"[digit % 16];
}

void do_work()
{
	printf("%c\n", digit_to_hex_char(15));

	char str[] = "hello world";
	printf("%s\n", str);
	str[2] = 'c';
	printf("%s\n", str);
	puts(str);

	char* pStr = "Hello World";
	printf("%s\n", pStr);
	puts(pStr);

	/*char inputStr[20];
	scanf("%s", inputStr);
	puts(inputStr);*/

	char inputStr2[20];
	gets_s(inputStr2, 20);
	puts(inputStr2);
}

/*接收输入的字符串*/
int read_line(char str[], int read_num)
{
	int ch, i = 0;

	while ((ch = getchar()) != '\n')
	{
		if (i < read_num)
		{
			str[i++] = ch;
		}
	}

	str[i] = '\0';

	return i;
}

void str_process()
{
	char* str = "hello";
	char strCpy[12];
	// 复制字符串
	strcpy(strCpy, str);
	printf("%s\n", strCpy);
	// 计算字符串的长度
	printf("%d\n", strlen(strCpy));
	// 比较两个字符串是否一样
	printf("%d\n", strcmp(str, strCpy));
	// 连接两个字符串，需要注意前面一个字符串数组的长度
	printf("%s\n", strcat(strCpy, str));
}

void reminder_test()
{
	char reminders[MAX_REMIND][MSG_LEN + 3]; // 存放提示的数组
	// 如何使用这个二维数组呢？我们将它的每一行当作一个字符串，reminders[i] 就是每个字符串的指针，如果你不理解可以去前面看看我们的数组的二维数组中的行如何访问；本节第七部分也会讨论二维数组存放字符串的问题。
	char day_str[3];//当前日期转换为字符串
	char msg_str[MSG_LEN + 1]; //当前输入的提示消息
	int day, num_remind = 0; // 日期和当前提示数
	int i, j;


	for (;;) {

		if (num_remind == MAX_REMIND) {
			printf("-- No space left --\n");
			break;
		}

		printf("Enter day and reminder:");

		scanf("%2d", &day); //每月的日期只用两个数表示即可，只读 2 个字段

		if (day == 0)
			break;

		sprintf(day_str, "%2d", day); // 将 day 以 "%2d" 的格式写入 day_str 字符数组中。"%2d" 保证小于10的天占两位右对齐
		read_line(msg_str, MSG_LEN);

		// 寻找当前输入的提示应该放到提示数组的那个位置
		for (i = 0; i < num_remind; i++) {
			// 说明当前输入的日期应该排在此行前
			if (strcmp(day_str, reminders[i]) < 0)
				break;
		}

		// 将当前输入的提示插入到正确的位置
		for (j = num_remind; j > i; j--) {
			strcpy(reminders[j], reminders[j - 1]);
		}

		strcpy(reminders[i], day_str);
		strcat(reminders[i], msg_str);// 刚好将 day_str 复制进去的空字符覆盖掉了

		num_remind++;
	}

	printf("Day Reminder: \n");
	for (i = 0; i < num_remind; i++)
		printf("%s\n", reminders[i]);

}

void nine_point()
{
	int offset = 5;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			switch (i)
			{
			case 0:
				show(offset * j - offset, -offset, 0);
				break;
			case 1:
				show(offset - offset * j, 0, 0);
				break;
			case 2:
				show(offset * j - offset, offset, 0);
				break;
			}
		}
	}
}

void show(int x, int y, int z)
{
	printf("%d\t%d\t%d\n", x, y, z);
}
