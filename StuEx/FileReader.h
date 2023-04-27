
// Copyright (c) Logic.Studio 
// Members:¡ı√˜ˆŒ°¢¡ı≥–Ωı°¢Ÿ°”ÍÔø
// SPDX-License-Identifier: MIT Lisense

#pragma once
#include <fileapi.h>
#include "CFilePicker.h"
#include "GlobalVar.h"

//TODO:This method will be replaced 
 void ReadFromText_Legacy(struct StudentInfo stu[])
 {
	 try {int i, j, re;
	 FILE* fp = fopen("002.txt", "r");
	 for (i = 0;; i++)
	 {
		 fscanf(fp, "%s	%s	%d	%s", stu[i].StuId, stu[i].StuName, &stu[i].StuGender, stu[i].StuClassIndex);
		 if (re == EOF) break;
	 }
	 fclose(fp);
	 for (j = 0; j < i; j++)
	 {
	//	 printf("%s,%s,%d,%s\n", stu[j].num, stu[j].clas, stu[j].s, stu[j].name);
	 }
	 }
	// FILE* filePoint = fopen((CONST char)filePath);
 }
