#define _CRT_SECURE_NO_WARNINGS 1

#include "Security.h"
#include <string.h>
#include <Windows.h>
#include <stdio.h>
#include <stdbool.h>
#include "systemInfo.h"
#include "md5.h"

int currentUser = 0;
bool isCheck = false;
bool havePermission = false;
char * user;
char regValue[100] = { 0 };

char sysBitReg[100] = { 0 };
int sysIntReg[100] = { 0 };
double sysDoubleReg[100] = { 0 };
char sysStrReg[100][100] = { 0 };

DLLAPI int GetCurUser()
{
	checkSecurity();
	return currentUser;
}

DLLAPI int ChangeUser(int nNewUser, char * szPassword)
{
	checkSecurity();

	setUser(nNewUser);

	readRegValue(TEXT("SOFTWARE\\AutoMationFrameWork\\User"), user, regValue);

	char decrypt[48]={0};
	getMd5(decrypt,szPassword);

	if (!strcmp(decrypt, regValue))
	{
		currentUser = nNewUser;
		return 1;
	}
	return 0;
}

DLLAPI int ChangePassword(int nNewUser, char * szOldPassword, char * szNewPassword)
{
	checkSecurity();

	setUser(nNewUser);

	readRegValue(TEXT("SOFTWARE\\AutoMationFrameWork\\User"), user, regValue);

	char decrypt[48]={0};
	getMd5(decrypt,szOldPassword);

	if (!strcmp(decrypt, regValue))
	{
		getMd5(decrypt,szNewPassword);
		setRegValue(TEXT("SOFTWARE\\AutoMationFrameWork\\User"), user, decrypt);
		return 1;
	}
	return 0;
}

DLLAPI char GetBit(int index)
{
	return sysBitReg[index];
}

DLLAPI void SetBit(int index, char value)
{
	sysBitReg[index] = value;
}

DLLAPI int GetInt(int index)
{
	return sysIntReg[index];
}

DLLAPI void SetInt(int index, int value)
{
	sysIntReg[index] = value;
}

DLLAPI double GetDouble(int index)
{
	return sysDoubleReg[index];
}

DLLAPI void SetDouble(int index, double value)
{
	sysDoubleReg[index] = value;
}

DLLAPI char * GetString(int index)
{
	char* value;
	value = (char *)malloc(100);
	strcpy(value, sysStrReg[index]);
	return value;
}

DLLAPI void SetString(int index, char* str)
{
	strcpy(sysStrReg[index], str);
}

void setUser(int num)
{
	switch (num)
	{
	case 0:
		user = TEXT("0");
		break;
	case 1:
		user = TEXT("1");
		break;
	case 2:
		user = TEXT("2");
		break;
	}
}

void checkSecurity()
{
	if (isCheck)
	{
		if (havePermission == false)
		{
			exit(0);
		}
	}
	else
	{
		isCheck = true;
		unsigned char checkStr[13] = { 0 };
		char checkDecrypt[48]={0};
		char checkValue[33]={0};

		getHardAndMac(checkStr);
		getMd5(checkDecrypt, checkStr);
		readRegValue(TEXT("SOFTWARE\\SosoVision\\User"), TEXT("register"), checkValue);

		if (strcmp(checkDecrypt,checkValue)!=0)/*ʹ�÷����������ж�*/
		{
			MessageBox(NULL, "ϵͳδע��!", "����", 1);
			exit(0);
		}
		else
		{
			havePermission = true;
		}
	}
}

void readRegValue(char * subKey, char * name, char * data)
{
	HKEY hkey = NULL;
	// ��ע���������Ҫע�⣬�����32λ�ĳ����64λ��ע�����Ҫ��Ȩ���Ǹ����������KEY_WOW64_64KEY�������
	// ��ע���������Ҫע�⣬�����64λ�ĳ����64λ��ע�����ʹ��RegOpenKeyExW�������
	long lr = RegOpenKeyEx(HKEY_LOCAL_MACHINE, subKey, 0, KEY_ALL_ACCESS | KEY_WOW64_64KEY, &hkey);
	if (ERROR_SUCCESS == lr)
	{
		DWORD dwValueCount = 0, maxValueNameLen = 0, maxValueDataLen = 0;
		// ��ȡע������Ϣ
		lr = RegQueryInfoKeyW(hkey, NULL, NULL, NULL, NULL, NULL, NULL, &dwValueCount, &maxValueNameLen, &maxValueDataLen, NULL, NULL);
		if (lr == ERROR_SUCCESS)
		{
			DWORD dwType = 0;
			char *lpData = (char *)malloc(maxValueDataLen);
			memset(lpData, 0, sizeof(maxValueDataLen));
			//const char data[100] = { 0 };
			// ��ȡ��ֵ������
			lr = RegQueryValueEx(hkey, name, NULL, &dwType, lpData, &maxValueDataLen);

			// ת�����ַ�����������unicode��������ÿ���ַ�����һ��\0��Ҫ��\0ȥ��
			for (unsigned i = 0, j = 0; i < maxValueDataLen; i ++, j++)
			{
				if (lpData[i] == '\0')
				{
					break;
				}
				printf("%c", lpData[i]);
				memcpy(data + j, lpData + i, 1);
			}
			printf("\n");

			//MessageBoxA(NULL, data, "��ʾ", 1);
			return;
		}
		//MessageBox(NULL, L"��ȡ��ֵ��Ϣʧ��", L"��ʾ", 1);
		strcpy(data, "error");
		return;
	}
	//RegCloseKey(hkey);
	strcpy(data, "error");
}

void setRegValue(char *subKey, char * valueName, char * data)
{
	HKEY hKey;
	// ��ע�������������򴴽���
	size_t lRet = RegCreateKeyEx(HKEY_LOCAL_MACHINE, subKey, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS | KEY_WOW64_64KEY, NULL, &hKey, NULL);
	if (lRet != ERROR_SUCCESS)
	{
		printf("error no RegCreateKeyEx %s\n", subKey);
		return;
	}

	// �޸�ע����ֵ��û���򴴽���
	// ���ü�ֵ
	lRet = RegSetValueEx(hKey, valueName, 0, REG_SZ, (CONST BYTE*)data, strlen(data));
	if (lRet != ERROR_SUCCESS)
	{
		printf("error no RegSetValueEx %s\n", valueName);
		return;
	}
	RegCloseKey(hKey);
}

void getHardAndMac(unsigned char * registerStr)
{
	char hardDiskNum[128] = { 0 };
	char mac[200] = { 0 };
	char front[14] = { 0 };
	char back[7] = { 0 };

	getHardDiskNumber(hardDiskNum);
	getMAC(mac);

	strncpy(front, hardDiskNum+6, 6);
	strncpy(back, hardDiskNum, 6);
	strcat(front, back);
	strcpy(registerStr, front);
	printf(registerStr);
}

void getMd5(char * decrypt, unsigned char * registerStr)
{
	unsigned char decryptS[16];
	MD5_CTX md5;
	MD5Init(&md5);
	MD5Update(&md5, registerStr, strlen((char *)registerStr));
	MD5Final(&md5, decryptS);
	sprintf_s(decrypt, 48, "%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
		decryptS[0],
		decryptS[1],
		decryptS[2],
		decryptS[3],
		decryptS[4],
		decryptS[5],
		decryptS[6],
		decryptS[7],
		decryptS[8],
		decryptS[9],
		decryptS[10],
		decryptS[11],
		decryptS[12],
		decryptS[13],
		decryptS[14],
		decryptS[15]);
	printf(decrypt);
}