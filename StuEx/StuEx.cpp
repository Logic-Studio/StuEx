// StuEx.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

// Copyright (c) Logic.Studio 
// Members:刘明鑫、刘承锦、佟雨锟
// SPDX-License-Identifier: MIT Lisense

#include<stdio.h>
#include "Payloads.h"
#include "FileReader.h"

//释放内存
void FreeMemory(StudentInfo* stuTemp,bool isExit)
{
	free(stuTemp);
	if (isExit)
	{
	exit(0);
	}
}

int main()
{

	//创建变量

	//包含学生全部信息
	//预先初始化stuInfo为大小为1的数组
	StudentInfo* stuInfo = (StudentInfo*)malloc(1 * sizeof(StudentInfo));
	bool IsExit = false;
	int choice;//选择模式
	//文字输入
	char stuId[12];
	char classIndex[7];

	do {
		printf("\n                                  ********** 学生信息管理系统 **********\n");
		printf("  1. 读入数据\n");
		printf("  2. 根据学号查询学生信息\n");
		printf("  3. 根据班号输出该班学生信息\n");
		printf("  4. 输出各个班的人数\n");
		printf("  5. 退出\n");
		printf("请选择菜单编号：");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
		{
			char* filePath = OpenFilePicker();
			stuInfo= ReadDataFile(filePath, stuInfo);
		}
		break;
		case 2:
			printf("请输入学号：");
			scanf("%s", stuId);
			SearchStudentInfoById(stuId, stuInfo, stuLength);
			break;
		case 3:
			printf("请输入班号：");
			scanf("%s", classIndex);
			PrintStudentInfoByClass(classIndex, stuInfo,stuLength);
			break;
		case 4:
			PrintClassCount(stuInfo);
			break;
		case 5:
			IsExit = true;
			FreeMemory(stuInfo,IsExit);
			printf("[Info] 程序已退出。\n");
			break;
		default:
			printf("[Warning] 无效的菜单选项，请重新输入。\n");
			break;
		}
	} while (choice != 5);
}

