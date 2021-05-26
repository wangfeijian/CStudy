#define _CRT_SECURE_NO_WARNINGS 1

#include <Windows.h>
#include <stdio.h>
#include <string.h>

void show()
{
	HKEY hkey = NULL;
	char *lpszSubKey = TEXT("SOFTWARE\\Cognex\\VisionPro");
	// 打开注册表，这里需要注意，如果是32位的程序打开64位的注册表，需要在权限那个参数中添加KEY_WOW64_64KEY这个参数
	long lr = RegOpenKeyExW(HKEY_LOCAL_MACHINE, lpszSubKey, 0, KEY_ALL_ACCESS|KEY_WOW64_64KEY, &hkey);
	if (ERROR_SUCCESS == lr)
	{
		DWORD dwValueCount=0,maxValueNameLen = 0,maxValueDataLen = 0;
		// 获取注册表键信息
		lr=RegQueryInfoKeyW(hkey,NULL,NULL,NULL,NULL,NULL,NULL,&dwValueCount,&maxValueNameLen,&maxValueDataLen,NULL,NULL);
		if (lr==ERROR_SUCCESS)
		{
			DWORD dwType = 0;
			char *lpData = (char *)malloc(maxValueDataLen);
			memset(lpData, 0, sizeof(maxValueDataLen));
			WCHAR data[100] = { 0 };
			// 获取键值的数据
			lr = RegQueryValueExW(hkey, L"VPROINSTDIR", NULL, &dwType, lpData, &maxValueDataLen);

			// 转换成字符串，由于是unicode编码所以每个字符后都有一个\0需要将\0去掉
			for (unsigned i = 0, j = 0; i < maxValueDataLen; i += 2, j++)
			{
				printf("%c", lpData[i]);
				memcpy(data + j, lpData + i, 1);
			}
			printf("\n");
			MessageBox(NULL, data, L"提示", 1);
		}
		MessageBox(NULL, L"打开成功", L"提示", 1);
	}
	RegCloseKey(hkey);
}


int main(int argc, char* argv[])
{
	show();
}
