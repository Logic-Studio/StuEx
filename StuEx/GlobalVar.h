//GlobalVar.h :�����˶���ȫ�ֱ������͵Ķ���

// Copyright (c) Logic.Studio 
// Members:�����Ρ����н���١���
// SPDX-License-Identifier: MIT Lisense

#pragma once

//ѧ����ѧ��Ӣ�����ķ���
struct Score
{
	int Math;
	int English;
	int Physics;
};

//ѧ����Ϣ����
 struct StudentInfo
{
	char StuId[12]; //ѧ��ѧ�ţ���������12����ʾ���ļ�002.txt
	char StuName[50]; //ѧ������
	char StuGender[4]; //ѧ���Ա�
	char StuClassIndex[8]; //ѧ���༶����
	Score StuScore; //ѧ���ɼ�
 };
 //ѧ������
 int stuLength = 1;