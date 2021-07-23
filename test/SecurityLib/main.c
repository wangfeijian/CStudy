#define _CRT_SECURE_NO_WARNINGS 1
#include "Security.h"
#include <string.h>
#include <Windows.h>
#include <stdio.h>


int main(int argc, char* argv[])
{
	setRegValue(TEXT("SOFTWARE\\AutoMationFrameWork\\User"), TEXT("0"),TEXT("test123"));
	setRegValue(TEXT("SOFTWARE\\AutoMationFrameWork\\User"), TEXT("1"),TEXT("test456"));
	setRegValue(TEXT("SOFTWARE\\AutoMationFrameWork\\User"), TEXT("2"),TEXT("test789"));
	int ret = ChangeUser(2, "test789");
	int userNum = GetCurUser();
	int changeRet = ChangePassword(2, "test789", TEXT("test7891"));
}
