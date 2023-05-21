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
void StuCount(int length)
{

	/////////////////////////////////
	///
	//
	// 以下代码有严重错误！！！！！
	//
	///
	/////////////////////////////////
	
	
	//struct TempId
	//{
	//char classIds[7];
	//};

	////TempId* copiedID = (TempId*)malloc(length * sizeof(TempId));
	//TempId copiedID[35];
	////拷贝stuId[]
	//for (int  i = 0; i < length; i++)
	//{

	//	strcpy(copiedID[i].classIds, stuInfo[i].StuClassIndex);
	//	//copiedID[i].classIds = stuInfo[i].StuClassIndex;
	//}
	//for (int i = 0; i < length; i++)
	//{
	//	for (int j = i+1; j < length; j++)
	//	{
	//		if (copiedID[i].classIds==copiedID[j].classIds)
	//		{
	//			for (int k = j; k < length - 1; k++)
	//			{
	//				copiedID[k] = copiedID[k + 1];
	//			}
	//			length--;
	//			j--;
	//		}
	//	}
	//}
	
	//for (int i = 0; i < length; i++)
	//{	int stuCount=0;
	//	short rightNum = 0;//字符匹配数
	//	for (int j = 0; j < 7; j++)
	//	{
	//		if (copiedID[j].classIds[j] == stuInfo[i].StuClassIndex[j]) {
	//			rightNum++;

	//		}
	//		if (rightNum == 7)  //已经全字匹配
	//		{
	//			stuCount++;
	//		}
	//	}
	//	printf("%s 班共有：         %d 人", copiedID[i].classIds, stuCount);
	//}


	int arrayLength=0;

	while (stuInfo[arrayLength].StuClassIndex!=NULL)
	{
		arrayLength++;
	}
	StudentInfo *p = (StudentInfo*)malloc(arrayLength * sizeof(StudentInfo));

	for (int i = 0; i < arrayLength; i++)
	{
		strcpy(p[arrayLength].StuClassIndex, stuInfo[arrayLength].StuClassIndex);
	}
}
