#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(const char* s1, const char* s2);

int main(int argc, char* argv[])
{
	char* s1 = "wang";
	char* s2 = "fei";

	char* ret = concat(s1, s2);

	printf(ret);
	getchar();
}


char* concat(const char* s1, const char* s2)
{
	char *ret = (char*)malloc(strlen(s1) + strlen(s2) + 1);

	if (ret==NULL)
	{
		printf("Error:malloc failed in concat.\n");
		exit(EXIT_FAILURE);
	}

	strcpy(ret, s1);
	strcat(ret, s2);

	return  ret;
}
