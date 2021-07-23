#define _CRT_SECURE_NO_WARNINGS 1

#include "Security.h"
#include <string.h>
#include <Windows.h>
#include <stdio.h>
#include <stdbool.h>

int currentUser = 0;
bool isCheck = false;
bool havePermission = false;
char * user;
char data[100] = { 0 };

DLLAPI int GetCurUser()
{
	checkSecurity();
	return currentUser;
}

DLLAPI int ChangeUser(int nNewUser, char * szPassword)
{
	checkSecurity();

	setUser(nNewUser);

	readRegValue(TEXT("SOFTWARE\\AutoMationFrameWork\\User"), user, data);

	if (!strcmp(szPassword, data))
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

	readRegValue(TEXT("SOFTWARE\\AutoMationFrameWork\\User"), user, data);

	if (!strcmp(szOldPassword, data))
	{
		setRegValue(TEXT("SOFTWARE\\AutoMationFrameWork\\User"), user, szNewPassword);
		return 1;
	}
	return 0;
}

const void setUser(int num)
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

const void checkSecurity()
{
	if (isCheck)
	{
		if (havePermission==false)
		{
			exit(0);
		}
	}
	else
	{
		isCheck = true;
		if (true)/*ʹ�÷����������ж�*/
		{
			MessageBox(NULL, "ϵͳδע��!", "����", 1);
			havePermission = true;
		}
		/*HKEY valueKey;
			RegOpenKeyA(HKEY_CURRENT_USER, L"AppEvents", &valueKey);
			if (ERROR_SUCCESS == RegOpenKeyA(HKEY_CURRENT_USER, L"Test", &valueKey))
			{
				printf("%p\n",valueKey);
				MessageBoxA(NULL, TEXT("ע�����"), TEXT("��ʾ"), 1);
			}*/
	}
}

const char * readRegValue(char * subKey, char * name, char * data)
{
	HKEY hkey = NULL;
	// ��ע���������Ҫע�⣬�����32λ�ĳ����64λ��ע�����Ҫ��Ȩ���Ǹ����������KEY_WOW64_64KEY�������
	long lr = RegOpenKeyEx(HKEY_LOCAL_MACHINE, subKey, 0, KEY_ALL_ACCESS|KEY_WOW64_64KEY, &hkey);
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
			lr = RegQueryValueExW(hkey, name, NULL, &dwType, lpData, &maxValueDataLen);

			// ת�����ַ�����������unicode��������ÿ���ַ�����һ��\0��Ҫ��\0ȥ��
			for (unsigned i = 0, j = 0; i < maxValueDataLen; i += 2, j++)
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
			return data;
		}
		//MessageBox(NULL, L"��ȡ��ֵ��Ϣʧ��", L"��ʾ", 1);
		return "error";
	}
	//RegCloseKey(hkey);
	return "error";
}

const void setRegValue(char *subKey, char * valueName, char * data)
{
	HKEY hKey;
	// ��ע�������������򴴽���
	size_t lRet = RegCreateKeyEx(HKEY_LOCAL_MACHINE, subKey, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS|KEY_WOW64_64KEY, NULL, &hKey, NULL);
	if (lRet != ERROR_SUCCESS)
	{
		printf("error no RegCreateKeyEx %ls\n", subKey);
		return;
	}

	// �޸�ע����ֵ��û���򴴽���
	// ���ü�ֵ
	lRet = RegSetValueEx(hKey, valueName, 0, REG_SZ, (CONST BYTE*)data, 128);
	if (lRet != ERROR_SUCCESS)
	{
		printf("error no RegSetValueEx %ls\n", valueName);
		return;
	}
	RegCloseKey(hKey);
}