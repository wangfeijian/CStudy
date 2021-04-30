#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "word.h"

int read_char(void)
{
	int ch = getchar();

	if (ch == '\n' || ch == '\t')
		return ' ';

	return ch;
}

void read_word(char* word, int len)
{
	int ch = 0;

	while ((ch == read_char()) == ' ')
		;

	int i = 0;
	while (ch != ' ' && ch != EOF)
	{
		if (i < len)
		{
			word[i++] = ch;
		}
		ch = read_char();
	}

	word[i] = '\0';
}
