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

void PrintStuInfoByClassId(char classId[], int length)
{
	for (int i = 0; i < length; i++)
	{
		bool isCorrect = false;
		short rightNum = 0;
		
		for (int j = 0; j < length; j++)
		{
			if (classId[j] == stuInfo[i].StuClassIndex[j]) //TODO:排查出严重问题，数组字符出现“？”
			{
				rightNum++;
			}
		}
		if (rightNum == 12)
		{
			isCorrect = true;
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
