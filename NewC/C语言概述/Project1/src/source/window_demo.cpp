#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdio.h>

const char* title = "���ڳ���ʾ��1";

double Average(double a, double b)
{
	return (a + b) / 2;
}

int WINAPI WinMain(HINSTANCE h, HINSTANCE d, LPSTR s, int m)
{
	double ave;
	char buff[80];

	ave = Average(123, 456);

	sprintf(buff, "ƽ��ֵ = %.2f", ave);

	MessageBox(NULL, buff, title, MB_OK);

	return 0;
}