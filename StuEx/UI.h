//UI.h :���ļ��������й���ʾЧ���ĺ���

// Copyright (c) Logic.Studio 
// Members:�����Ρ����н���١���
// SPDX-License-Identifier: MIT Lisense

#include <Windows.h>
#include <stdio.h>
#include "GlobalVar.h"
#include <time.h>

#define LONG_SLEEP_TIME 1000
#define SHORT_SLEEP_TIME 250


  
  /*����������ʾ��ɫ
	0 = ��ɫ       8 = ��ɫ
	1 = ��ɫ       9 = ����ɫ
	2 = ��ɫ       A = ����ɫ
	3 = ǳ��ɫ     B = ��ǳ��ɫ
	4 = ��ɫ       C = ����ɫ
	5 = ��ɫ       D = ����ɫ
	6 = ��ɫ       E = ����ɫ
	7 = ��ɫ       F = ����ɫ
  */
 void Color(short x)

{
	if (x >= 0 && x <= 15)// Parameters in the range of 0-15 colors
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);  // With only one argument, change the font color
	else// The default color is white
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);


}

 //�����������˺����д���Χ������
int RandNum()
{
	srand((unsigned)time(NULL));
	return rand();
}

int RandNum(int minRange, int maxRange)
{
	srand((unsigned)time(NULL));
	return rand() % maxRange + minRange;
}

