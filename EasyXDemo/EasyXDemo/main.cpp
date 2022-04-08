#define _CRT_SECURE_NO_WARNINGS 1

#include <easyx.h>
#include <mmsystem.h>

#pragma comment(lib, "Winmm.lib")

int main()
{
	initgraph(1920, 1080);
	setbkcolor(WHITE);
	cleardevice();

	IMAGE image;
	for (int i = 1; i < 11; i++)
	{
		char temp[1];
		_itoa(i, temp, 10);
		char * ext = ".jpg";
		char * str = strcat(temp, ext);
		char mPath[] = "D:/Desktop Image/";
		char * path = strcat(mPath, str);
		loadimage(&image, LPCTSTR(path));
		putimage(0, 0, &image);
		Sleep(1000);
	}

	ExMessage message;
	while (true)
	{
		
		getmessage(&message);
		if (message.lbutton)
			MessageBox(nullptr, "ABC", "tip", 0);
	}
}
