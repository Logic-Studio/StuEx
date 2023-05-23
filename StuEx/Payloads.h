//Payload.h : ���ļ������˳����������Ҫ����

// Copyright (c) Logic.Studio 
// Members:�����Ρ����н���١���
// SPDX-License-Identifier: MIT Lisense

#include "GlobalVar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����ѧ�Ų���ѧ��
void SearchStudentInfoById(char stuId[],StudentInfo stuTemp[], int length)
{
	int numIndex = 1;
	bool isCorrect = false; 
	for (int i = 0; i < length; i++)
	{	//ȫ��ƥ�����
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
			printf("ƥ�䵽����ѧԱ��\n");
			printf(" �� ��       ѧ��         ����       �Ա�   �༶    ��ѧ    Ӣ��    ����\n");
			printf("-----------------------------------------------------------------------\n");
			printf("   %-2d     %-12.12s    %-10s %-4s  %-8s  %-3d     %-3d     %-3d\n",numIndex, stuTemp[i].StuId, stuTemp[i].StuName, stuTemp[i].StuGender,
				stuTemp[i].StuClassIndex, stuTemp[i].StuScore.Math, stuTemp[i].StuScore.English, stuTemp[i].StuScore.Physics);
			numIndex++;
		}
		
	}
}

//���ݰ༶�Ų���ѧ��
void PrintStudentInfoByClass(char classId[], StudentInfo stuTemp[], int length)
{		
		int numIndex =1;
		printf("ƥ�䵽����ѧԱ��\n");
		printf(" �� ��     ѧ��         ����        �Ա�   �༶    ��ѧ  Ӣ��  ����\n");
		printf("-----------------------------------------------------------------------\n");

	for (int i = 0; i < length; i++)
	{
		short rightNum = 0;//�ַ�ƥ����
		for ( int j = 0; j < 7; j++)
		{
			if (classId[j] == stuTemp[i].StuClassIndex[j]) {
				rightNum++;

			}		
			if (rightNum==7)  //�Ѿ�ȫ��ƥ��
			{
				
			printf("   %-2d     %-12.12s  %-10s  %-4s  %-8s  %-3d   %-3d   %-3d\n", numIndex,stuTemp[i].StuId, stuTemp[i].StuName, stuTemp[i].StuGender,
				stuTemp[i].StuClassIndex, stuTemp[i].StuScore.Math, stuTemp[i].StuScore.English, stuTemp[i].StuScore.Physics);
			numIndex++;
		}
		}

	}

}


//ͳ�Ƹ����༶������
void PrintClassCount(StudentInfo stuTemp[])
{
		//����stuInfo�еİ༶�ŵ�classId������

	char classId[35][8] = { 0 };
	for (int i = 0; i < 35; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				classId[i][j] = stuTemp[i].StuClassIndex[j]+'\0';
			}
	}
	//classId����ȥ��
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
	//ͳ�Ƹ����༶������
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
	//��������༶������
	printf("�����༶���������£�\n");	
	printf("----------------------------------------------------------------\n");

	for (int i = 0; i < classIdNoRepeatNum; i++)
	{
		printf("%s �༶������Ϊ��      %d\n", classIdNoRepeat[i], classNum[i]);
	}
	printf("\n���ƣ�                      %d\n", total);
}


