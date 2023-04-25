
// Copyright (c) Logic.Studio 
// Members:¡ı√˜ˆŒ°¢¡ı≥–Ωı°¢Ÿ°”ÍÔø
// SPDX-License-Identifier: MIT Lisense

#pragma once
#include <string>
using namespace std;
 struct StudentInfo
{
	char StuId[12]; //The Id number of the student,12 is based on the example file
	char StuName[50]; //The name of the student
	char StuGender[4]; //The Gender of the student
	char StuClassIndex[16]; //The class of the student belongs to
	double StuScore; //The score of the student
};
 enum SubjectEnum
{
	math=0,
	english=1,
	physic=2
};

 string filePath; 