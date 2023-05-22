
// Copyright (c) Logic.Studio 
// Members:刘明鑫、刘承锦、佟雨锟
// SPDX-License-Identifier: MIT Lisense

#include <Windows.h>
#include <stdio.h>
#include "GlobalVar.h"
#include <time.h>

#define LONG_SLEEP_TIME 1000
#define SHORT_SLEEP_TIME 250


  
  /*0 = 黑色       8 = 灰色
	1 = 蓝色       9 = 淡蓝色
	2 = 绿色       A = 淡绿色
	3 = 浅绿色     B = 淡浅绿色
	4 = 红色       C = 淡红色
	5 = 紫色       D = 淡紫色
	6 = 黄色       E = 淡黄色
	7 = 白色       F = 亮白色
  */
void Color(short x)

{
	if (x >= 0 && x <= 15)// Parameters in the range of 0-15 colors
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);  // With only one argument, change the font color
	else// The default color is white
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);


}
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


void FreeMemory(StudentInfo *stuTemp)
{
	free(stuTemp);
}