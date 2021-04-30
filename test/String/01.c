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

/*����������ַ���*/
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
	// �����ַ���
	strcpy(strCpy, str);
	printf("%s\n", strCpy);
	// �����ַ����ĳ���
	printf("%d\n", strlen(strCpy));
	// �Ƚ������ַ����Ƿ�һ��
	printf("%d\n", strcmp(str, strCpy));
	// ���������ַ�������Ҫע��ǰ��һ���ַ�������ĳ���
	printf("%s\n", strcat(strCpy, str));
}

void reminder_test()
{
	char reminders[MAX_REMIND][MSG_LEN + 3]; // �����ʾ������
	// ���ʹ�������ά�����أ����ǽ�����ÿһ�е���һ���ַ�����reminders[i] ����ÿ���ַ�����ָ�룬����㲻������ȥǰ�濴�����ǵ�����Ķ�ά�����е�����η��ʣ����ڵ��߲���Ҳ�����۶�ά�������ַ��������⡣
	char day_str[3];//��ǰ����ת��Ϊ�ַ���
	char msg_str[MSG_LEN + 1]; //��ǰ�������ʾ��Ϣ
	int day, num_remind = 0; // ���ں͵�ǰ��ʾ��
	int i, j;


	for (;;) {

		if (num_remind == MAX_REMIND) {
			printf("-- No space left --\n");
			break;
		}

		printf("Enter day and reminder:");

		scanf("%2d", &day); //ÿ�µ�����ֻ����������ʾ���ɣ�ֻ�� 2 ���ֶ�

		if (day == 0)
			break;

		sprintf(day_str, "%2d", day); // �� day �� "%2d" �ĸ�ʽд�� day_str �ַ������С�"%2d" ��֤С��10����ռ��λ�Ҷ���
		read_line(msg_str, MSG_LEN);

		// Ѱ�ҵ�ǰ�������ʾӦ�÷ŵ���ʾ������Ǹ�λ��
		for (i = 0; i < num_remind; i++) {
			// ˵����ǰ���������Ӧ�����ڴ���ǰ
			if (strcmp(day_str, reminders[i]) < 0)
				break;
		}

		// ����ǰ�������ʾ���뵽��ȷ��λ��
		for (j = num_remind; j > i; j--) {
			strcpy(reminders[j], reminders[j - 1]);
		}

		strcpy(reminders[i], day_str);
		strcat(reminders[i], msg_str);// �պý� day_str ���ƽ�ȥ�Ŀ��ַ����ǵ���

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
