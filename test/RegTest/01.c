#define _CRT_SECURE_NO_WARNINGS 1

#include <Windows.h>
#include <stdio.h>
#include <string.h>

void show()
{
	HKEY hkey = NULL;
	char *lpszSubKey = TEXT("SOFTWARE\\Cognex\\VisionPro");
	// ��ע���������Ҫע�⣬�����32λ�ĳ����64λ��ע�����Ҫ��Ȩ���Ǹ����������KEY_WOW64_64KEY�������
	long lr = RegOpenKeyExW(HKEY_LOCAL_MACHINE, lpszSubKey, 0, KEY_ALL_ACCESS|KEY_WOW64_64KEY, &hkey);
	if (ERROR_SUCCESS == lr)
	{
		DWORD dwValueCount=0,maxValueNameLen = 0,maxValueDataLen = 0;
		// ��ȡע������Ϣ
		lr=RegQueryInfoKeyW(hkey,NULL,NULL,NULL,NULL,NULL,NULL,&dwValueCount,&maxValueNameLen,&maxValueDataLen,NULL,NULL);
		if (lr==ERROR_SUCCESS)
		{
			DWORD dwType = 0;
			char *lpData = (char *)malloc(maxValueDataLen);
			memset(lpData, 0, sizeof(maxValueDataLen));
			WCHAR data[100] = { 0 };
			// ��ȡ��ֵ������
			lr = RegQueryValueExW(hkey, L"VPROINSTDIR", NULL, &dwType, lpData, &maxValueDataLen);

			// ת�����ַ�����������unicode��������ÿ���ַ�����һ��\0��Ҫ��\0ȥ��
			for (unsigned i = 0, j = 0; i < maxValueDataLen; i += 2, j++)
			{
				printf("%c", lpData[i]);
				memcpy(data + j, lpData + i, 1);
			}
			printf("\n");
			MessageBox(NULL, data, L"��ʾ", 1);
		}
		MessageBox(NULL, L"�򿪳ɹ�", L"��ʾ", 1);
	}
	RegCloseKey(hkey);
}


int main(int argc, char* argv[])
{
	show();
}
