#pragma once
#include "GlobalVar.h"
struct ClassInfo
{
	char className[7];
	int count;
};
void SearchStuInfoById(char stuId[],int length)
{

	for (int i = 0; i < length; i++)
	{	
		bool isCorrect = false;
		for (int j = 0; j < length; j++)
		{
			if (stuId[j]== stuInfo[i].StuId[j])
			{
				isCorrect = true;
			}
		}
		if (isCorrect==true)
		{
			printf("----------------------------------------------------------------\n");
			printf("匹配到以下学员：\n");
			printf("  学号            姓名   性别   班级     数学    英语    物理\n");
			printf("----------------------------------------------------------------\n");
			printf("%s  %s  %s   %s %d %d %d\n", stuInfo[i].StuId, stuInfo[i].StuName, stuInfo[i].StuGender,
				stuInfo[i].StuClassIndex, stuInfo[i].StuScore.Math, stuInfo[i].StuScore.English, stuInfo[i].StuScore.Physics);
		}
	}
}
//void SearchStuInfoById(char stuId[])
//{
//	for (int i = 0; i < 35; i++)
//	{
//		if (stuId == stuInfo[i].StuId)
//		{
//			printf("匹配到以下学员：\n");
//			printf("  学号           姓名   性别   班级     数学    英语    物理\n");
//			printf("----------------------------------------------------------------\n");
//			printf("%s  %s  %s   %s %d %d %d\n", stuInfo[i].StuId, stuInfo[i].StuName, stuInfo[i].StuGender,
//				stuInfo[i].StuClassIndex, stuInfo[i].StuScore.Math, stuInfo[i].StuScore.English, stuInfo[i].StuScore.Physics);
//		}
//	}
//}
void PrintStuInfoByClassId(char classId[], int length)
{
	for (int i = 0; i < length; i++)
	{
		bool isCorrect = false;
		for (int j = 0; j < length; j++)
		{
			if (classId[j] == stuInfo[i].StuClassIndex[j])
			{
				isCorrect = true;
			}
		}
		if (isCorrect ==true)
		{
			printf("匹配到以下学员：\n");
			printf("  学号           姓名   性别   班级     数学    英语    物理\n");
			printf("----------------------------------------------------------------\n");
			printf("%s  %s  %s   %s %d %d %d\n", stuInfo[i].StuId, stuInfo[i].StuName, stuInfo[i].StuGender,
				stuInfo[i].StuClassIndex, stuInfo[i].StuScore.Math, stuInfo[i].StuScore.English, stuInfo[i].StuScore.Physics);
		}
	}
}

void StuCount(int length)
{
	
	/*int count = 0;

	ClassInfo classArray[100];
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (stuInfo[i].StuClassIndex == stuInfo[j].StuClassIndex) 
			{
				classArray[count].className = stuInfo[i].StuClassIndex;
				count++;
			}
		}
	}
	*/
}
