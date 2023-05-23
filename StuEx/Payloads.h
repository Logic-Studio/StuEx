//Payload.h : 此文件定义了程序的所有主要功能

// Copyright (c) Logic.Studio 
// Members:刘明鑫、刘承锦、佟雨锟
// SPDX-License-Identifier: MIT Lisense

#include "GlobalVar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//根据学号查找学生
void SearchStudentInfoById(char stuId[],StudentInfo stuTemp[], int length)
{
	int numIndex = 1;
	bool isCorrect = false; 
	for (int i = 0; i < length; i++)
	{	//全字匹配检验
		isCorrect = false;
		int rightNum = 0;
		for (int j = 0; j < length; j++)
		{
			if (stuId[j]== stuTemp[i].StuId[j])
			{
				rightNum++;
			}
		}
		if (rightNum ==12)
		{
			isCorrect = true;
		}

		if (isCorrect != false)
		{
			printf("-----------------------------------------------------------------------\n");
			printf("匹配到以下学员：\n");
			printf(" 序 号       学号         姓名       性别   班级    数学    英语    物理\n");
			printf("-----------------------------------------------------------------------\n");
			printf("   %-2d     %-12.12s    %-10s %-4s  %-8s  %-3d     %-3d     %-3d\n",numIndex, stuTemp[i].StuId, stuTemp[i].StuName, stuTemp[i].StuGender,
				stuTemp[i].StuClassIndex, stuTemp[i].StuScore.Math, stuTemp[i].StuScore.English, stuTemp[i].StuScore.Physics);
			numIndex++;
		}
		
	}
}

//根据班级号查找学生
void PrintStudentInfoByClass(char classId[], StudentInfo stuTemp[], int length)
{		
		int numIndex =1;
		printf("匹配到以下学员：\n");
		printf(" 序 号     学号         姓名        性别   班级    数学  英语  物理\n");
		printf("-----------------------------------------------------------------------\n");

	for (int i = 0; i < length; i++)
	{
		short rightNum = 0;//字符匹配数
		for ( int j = 0; j < 7; j++)
		{
			if (classId[j] == stuTemp[i].StuClassIndex[j]) {
				rightNum++;

			}		
			if (rightNum==7)  //已经全字匹配
			{
				
			printf("   %-2d     %-12.12s  %-10s  %-4s  %-8s  %-3d   %-3d   %-3d\n", numIndex,stuTemp[i].StuId, stuTemp[i].StuName, stuTemp[i].StuGender,
				stuTemp[i].StuClassIndex, stuTemp[i].StuScore.Math, stuTemp[i].StuScore.English, stuTemp[i].StuScore.Physics);
			numIndex++;
		}
		}

	}

}


//统计各个班级的人数
void PrintClassCount(StudentInfo stuTemp[])
{
		//拷贝stuInfo中的班级号到classId数组中

	char classId[35][8] = { 0 };
	for (int i = 0; i < 35; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				classId[i][j] = stuTemp[i].StuClassIndex[j]+'\0';
			}
	}
	//classId数组去重
	char classIdNoRepeat[36][8] = { 0 };
	int classIdNoRepeatNum = 0;
	for (int i = 0; i < 35; i++)
	{
		bool isRepeat = false;
		for (int j = 0; j < classIdNoRepeatNum; j++)
		{
			if (strcmp(classId[i], classIdNoRepeat[j]) == 0)
			{
				isRepeat = true;
				break;
			}
		}
		if (isRepeat == false)
		{
			strcpy(classIdNoRepeat[classIdNoRepeatNum], classId[i]);
			classIdNoRepeatNum++;
		}
	}
	//统计各个班级的人数
	int classNum[35] = { 0 };
	for (int i = 0; i < classIdNoRepeatNum; i++)
	{
		for (int j = 0; j < 35; j++)
		{
			if (strcmp(classIdNoRepeat[i], stuTemp[j].StuClassIndex) == 0)
			{
				classNum[i]++;
			}
		}
	}
	int total = 0;
	for (int i = 0; i < classIdNoRepeatNum; i++)
	{
		total += classNum[i];
	}
	//输出各个班级的人数
	printf("各个班级的人数如下：\n");	
	printf("----------------------------------------------------------------\n");

	for (int i = 0; i < classIdNoRepeatNum; i++)
	{
		printf("%s 班级的人数为：      %d\n", classIdNoRepeat[i], classNum[i]);
	}
	printf("\n共计：                      %d\n", total);
}


