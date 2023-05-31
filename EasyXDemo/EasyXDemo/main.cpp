#define _CRT_SECURE_NO_WARNINGS 1
#ifdef UNICODE
#undef UNICODE
#endif

#include <easyx.h>
#include <mmsystem.h>
#include <ctime>
#include <stdio.h>

#pragma comment(lib, "Winmm.lib")

void paint()
{
	// ������ͼ����
	initgraph(640, 480);

	// ����������(ͨ������������)
	float H = 190;		// ɫ��
	float S = 1;		// ���Ͷ�
	float L = 0.7f;		// ����
	for(int y = 0; y < 480; y++)
	{
		L += 0.0005f;
		setlinecolor( HSLtoRGB(H, S, L) );
		line(0, y, 639, y);
	}

	// ���ʺ�(ͨ��ɫ��������)
	H = 0;
	S = 1;
	L = 0.5f;
	setlinestyle(PS_SOLID, 2);		// �����߿�Ϊ 2
	for(int r = 400; r > 344; r--)
	{
		H += 5;
		setlinecolor( HSLtoRGB(H, S, L) );
		circle(500, 480, r);
	}
}

void showImage()
{
	initgraph(960, 540);
	setbkcolor(WHITE);
	cleardevice();
	IMAGE image;
	for (int i = 1; i < 11; i++)
	{
	/*	char temp[1];
		_itoa(i, temp, 10);
		char * ext = ".jpg";
		char * str = strcat(temp, ext);
		char mPath[] = "D:/Desktop Image/";
		char * path = strcat(mPath, str);*/
		char path[50];
		sprintf_s(path, "D:/Desktop Image/%d.jpg", i);
		loadimage(&image, path, 960, 540);
		putimage(0, 0, &image);
		Sleep(1000);
	}




	ExMessage message;
	while (true)
	{
		getmessage(&message);
		flushmessage();
		if (message.lbutton)
		{
			char str[100];
			InputBox(str, 100, "������һЩ����");
			MessageBox(nullptr, str, "tip", 0 | MB_SYSTEMMODAL);
		}
	}
}

void showStr()
{
	// �����������
	srand((unsigned) time(NULL));

	// ��ʼ��ͼ��ģʽ
	initgraph(640, 480);

	int  x, y;
	char c;

	settextstyle(16, 8, "Courier");	// ��������

	// ������ɫ
	settextcolor(GREEN);
	setlinecolor(BLACK);

	for (int i = 0; i <= 479; i++)
	{
		// �����λ����ʾ���������ĸ
		for (int j = 0; j < 3; j++)
		{
			x = (rand() % 80) * 8;
			y = (rand() % 20) * 24;
			c = (rand() % 26) + 65;
			outtextxy(x, y, c);
		}

		// ���߲���һ��������
		line(0, i, 639, i);

		Sleep(10);					// ��ʱ
		if (i >= 479)	i = -1;
	}

	// �ر�ͼ��ģʽ
	closegraph();
}

#define MAXSTAR 200	// ��������

struct STAR
{
	double	x;
	int		y;
	double	step;
	int		color;
};

STAR star[MAXSTAR];

// ��ʼ������
void InitStar(int i)
{
	star[i].x = 0;
	star[i].y = rand() % 480;
	star[i].step = (rand() % 5000) / 1000.0 + 1;
	star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);	// �ٶ�Խ�죬��ɫԽ��
	star[i].color = RGB(star[i].color, star[i].color, star[i].color);
}

// �ƶ�����
void MoveStar(int i)
{
	// ����ԭ��������
	putpixel((int)star[i].x, star[i].y, 0);

	// ������λ��
	star[i].x += star[i].step;
	if (star[i].x > 640)	InitStar(i);

	// ��������
	putpixel((int)star[i].x, star[i].y, star[i].color);
}

void showStar()
{
	srand((unsigned)time(NULL));	// �������
	initgraph(640, 480);			// ������ͼ����

	// ��ʼ����������
	for(int i = 0; i < MAXSTAR; i++)
	{
		InitStar(i);
		star[i].x = rand() % 640;
	}

	// �����ǿգ���������˳�
	while (true)
	{
		for(int i = 0; i < MAXSTAR; i++)
			MoveStar(i);
		Sleep(20);
	}
}

int main()
{
	showImage();
	//paint();
	//showStr();
	//showStar();
	while (true);
}
