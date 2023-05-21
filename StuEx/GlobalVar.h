
// Copyright (c) Logic.Studio 
// Members:¡ı√˜ˆŒ°¢¡ı≥–Ωı°¢Ÿ°”ÍÔø
// SPDX-License-Identifier: MIT Lisense

#pragma once
#include <string>
using namespace std;

struct Score
{
	int Math;
	int English;
	int Physics;
};
 struct StudentInfo
{
	char StuId[12]; //The Id number of the student,12 is based on the example file
	char StuName[50]; //The name of the student
	char StuGender[4]; //The Gender of the student
	char StuClassIndex[7]; //The class of the student belongs to
	Score StuScore; //The score of the student
 };
 enum SubjectEnum
{
	math=0,
	english=1,
	physic=2
};
 int stuLength = 0;
 string filePath; 
 //∂ØÃ¨∑÷≈‰
StudentInfo* stuInfo = (StudentInfo*)malloc(stuLength * sizeof(StudentInfo));
