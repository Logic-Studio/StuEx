
// Copyright (c) Logic.Studio 
// Members:ÁõÃ÷öÎ¡¢Áõ³Ğ½õ¡¢Ù¡Óêï¿
// SPDX-License-Identifier: MIT Lisense

#pragma once
#include <string>
using namespace std;
extern struct StudentInfo
{
	string StuId; //The Id number of the student
	string StuName; //The name of the student
	string StuGender; //The Gender of the student
	string StuIndex; //The class of the student belongs to
	double StuScore; //The score of the student
};
extern enum SubjectEnum
{
	math=0,
	english=1,
	physic=2
};

extern string filePath; 