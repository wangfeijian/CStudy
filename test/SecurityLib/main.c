#define _CRT_SECURE_NO_WARNINGS 1
#include "Security.h"
#include <string.h>
#include <Windows.h>
#include <stdio.h>
#include "systemInfo.h"
#include "md5.h"

int main(int argc, char* argv[])
{
	// 注册的时候使用
	unsigned char registerStr[11] = { 0 };
	char decrypt[48]={0};
	getMd5(decrypt,TEXT("test123"));
	setRegValue(TEXT("SOFTWARE\\SosoVision\\User"), TEXT("0"),decrypt);
	getMd5(decrypt,TEXT("test456"));
	setRegValue(TEXT("SOFTWARE\\SosoVision\\User"), TEXT("1"),decrypt);
	getMd5(decrypt,TEXT("test789"));
	setRegValue(TEXT("SOFTWARE\\SosoVision\\User"), TEXT("2"),decrypt);
	getHardAndMac(registerStr);
	getMd5(decrypt,registerStr);
	setRegValue(TEXT("SOFTWARE\\SosoVision\\User"), TEXT("register"), decrypt);

	//测试权限
	ChangeUser(2, TEXT("test456"));
	//ChangePassword(1, "test158", "test456");
	checkSecurity();

	//测试寄存器
	char str[100] = { 0 };
	SetBit(1, 1);
	char c = GetBit(1);
	SetInt(1, 156);
	int i = GetInt(1);
	SetDouble(1, 3.56);
	double d = GetDouble(1);
	SetString(2, "test");
	GetString(2,str);
	printf(str);
}
