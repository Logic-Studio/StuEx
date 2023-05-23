//GlobalVar.h :包含了对于全局变量类型的定义

// Copyright (c) Logic.Studio 
// Members:刘明鑫、刘承锦、佟雨锟
// SPDX-License-Identifier: MIT Lisense

#pragma once

//学生数学、英语、物理的分数
struct Score
{
	int Math;
	int English;
	int Physics;
};

//学生信息类型
 struct StudentInfo
{
	char StuId[12]; //学生学号，数组容量12基于示例文件002.txt
	char StuName[50]; //学生姓名
	char StuGender[4]; //学生性别
	char StuClassIndex[8]; //学生班级归属
	Score StuScore; //学生成绩
 };
 //学生人数
 int stuLength = 1;