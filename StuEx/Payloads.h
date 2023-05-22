
// Copyright (c) Logic.Studio 
// Members:刘明鑫、刘承锦、佟雨锟
// SPDX-License-Identifier: MIT Lisense

#include "GlobalVar.h"

//根据学号查找学生
void SearchStuInfoById(char stuId[],int length)  
{

	for (int i = 0; i < length; i++)
	{	//全字匹配检验
		bool isCorrect = false; //Initialize the check value
		short rightNum = 0;
		for (int j = 0; j < length; j++)
		{
			if (stuId[j]== stuInfo[i].StuId[j])
			{
				rightNum++;
			}
		}
		if (rightNum ==12)
		{
			isCorrect = true;
		}

		if (isCorrect==true)
		{
			printf("----------------------------------------------------------------\n");
			printf("匹配到以下学员：\n");
			printf("  学号            姓名   性别   班级     数学    英语    物理\n");
			printf("----------------------------------------------------------------\n");
			printf("%12s  %s  %s   %s %d %d %d\n", stuInfo[i].StuId, stuInfo[i].StuName, stuInfo[i].StuGender,
				stuInfo[i].StuClassIndex, stuInfo[i].StuScore.Math, stuInfo[i].StuScore.English, stuInfo[i].StuScore.Physics);
		}
	}
}

//根据班级号查找学生
void PrintStuInfoByClassId(char classId[], int length)
{
		printf("匹配到以下学员：\n");
		printf("  学号           姓名   性别   班级     数学    英语    物理\n");
		printf("----------------------------------------------------------------\n");

	for (int i = 0; i < length; i++)
	{
		short rightNum = 0;//字符匹配数
		for ( int j = 0; j < 7; j++)
		{
			if (classId[j] == stuInfo[i].StuClassIndex[j]) {
				rightNum++;

			}		
			if (rightNum==7)  //已经全字匹配
		{
			printf("%s  %s  %s   %s %d %d %d\n", stuInfo[i].StuId, stuInfo[i].StuName, stuInfo[i].StuGender,
				stuInfo[i].StuClassIndex, stuInfo[i].StuScore.Math, stuInfo[i].StuScore.English, stuInfo[i].StuScore.Physics);
		}
		}

	}

}


//统计各个班级的人数
void GetStuNumInClass() 
{
		//拷贝stuInfo中的班级号到classId数组中

	char classId[35][7] = { 0 };
	for (int i = 0; i < 35; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				classId[i][j] = stuInfo[i].StuClassIndex[j]+'\0';
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
			if (strcmp(classIdNoRepeat[i], stuInfo[j].StuClassIndex) == 0)
			{
				classNum[i]++;
			}
		}
	}
	//输出各个班级的人数
	printf("各个班级的人数如下：\n");
	for (int i = 0; i < classIdNoRepeatNum; i++)
	{
		printf("%s班级的人数为：%d\n", classIdNoRepeat[i], classNum[i]);
	}

}
