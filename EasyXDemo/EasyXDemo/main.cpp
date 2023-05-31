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
	// 创建绘图窗口
	initgraph(640, 480);

	// 画渐变的天空(通过亮度逐渐增加)
	float H = 190;		// 色相
	float S = 1;		// 饱和度
	float L = 0.7f;		// 亮度
	for(int y = 0; y < 480; y++)
	{
		L += 0.0005f;
		setlinecolor( HSLtoRGB(H, S, L) );
		line(0, y, 639, y);
	}

	// 画彩虹(通过色相逐渐增加)
	H = 0;
	S = 1;
	L = 0.5f;
	setlinestyle(PS_SOLID, 2);		// 设置线宽为 2
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
			InputBox(str, 100, "请输入一些文字");
			MessageBox(nullptr, str, "tip", 0 | MB_SYSTEMMODAL);
		}
	}
}

void showStr()
{
	// 设置随机种子
	srand((unsigned) time(NULL));

	// 初始化图形模式
	initgraph(640, 480);

	int  x, y;
	char c;

	settextstyle(16, 8, "Courier");	// 设置字体

	// 设置颜色
	settextcolor(GREEN);
	setlinecolor(BLACK);

	for (int i = 0; i <= 479; i++)
	{
		// 在随机位置显示三个随机字母
		for (int j = 0; j < 3; j++)
		{
			x = (rand() % 80) * 8;
			y = (rand() % 20) * 24;
			c = (rand() % 26) + 65;
			outtextxy(x, y, c);
		}

		// 画线擦掉一个像素行
		line(0, i, 639, i);

		Sleep(10);					// 延时
		if (i >= 479)	i = -1;
	}

	// 关闭图形模式
	closegraph();
}

#define MAXSTAR 200	// 星星总数

struct STAR
{
	double	x;
	int		y;
	double	step;
	int		color;
};

STAR star[MAXSTAR];

// 初始化星星
void InitStar(int i)
{
	star[i].x = 0;
	star[i].y = rand() % 480;
	star[i].step = (rand() % 5000) / 1000.0 + 1;
	star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);	// 速度越快，颜色越亮
	star[i].color = RGB(star[i].color, star[i].color, star[i].color);
}

// 移动星星
void MoveStar(int i)
{
	// 擦掉原来的星星
	putpixel((int)star[i].x, star[i].y, 0);

	// 计算新位置
	star[i].x += star[i].step;
	if (star[i].x > 640)	InitStar(i);

	// 画新星星
	putpixel((int)star[i].x, star[i].y, star[i].color);
}

void showStar()
{
	srand((unsigned)time(NULL));	// 随机种子
	initgraph(640, 480);			// 创建绘图窗口

	// 初始化所有星星
	for(int i = 0; i < MAXSTAR; i++)
	{
		InitStar(i);
		star[i].x = rand() % 640;
	}

	// 绘制星空，按任意键退出
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
