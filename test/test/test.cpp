#include "stdafx.h"
#include <iostream>
#include "test.h"
#include <string>

static int a;

MyDllSpace::MyDllClass::MyDllClass()
{
}

MyDllSpace::MyDllClass::MyDllClass(double a)
{
}

extern "C" MYDLL_API double multiply(double b)
{
	return b*b;
}

extern "C" MYDLL_API void show()
{
	if(!a)
	{
		MyDllSpace::MyDllClass::show2();
		a++;
	}
	MessageBox(GetForegroundWindow(), "δע�ᣬ��ע��", "����", MB_OK);
	exit(1);
}

MYDLL_API void MyDllSpace::MyDllClass::show2()
{
	MessageBox(GetForegroundWindow(), "��ע��", "����", 1);
}

