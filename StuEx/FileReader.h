
// Copyright (c) Logic.Studio 
// Members:刘明鑫、刘承锦、佟雨锟
// SPDX-License-Identifier: MIT Lisense

#pragma once
#include <fileapi.h>
#include "CFilePicker.h"
#include "GlobalVar.h"
#include <stdio.h>
#include <iostream>
#ifdef _WIN32
#include <direct.h>
#elif __APPLE__ || __linux__
#include<unistd.h>
#endif
//TODO:This method will be replaced 
 void ReadFromText_Legacy(struct StudentInfo stu[])
 {
	 char runPath[1024] = { 0 };
	 _getcwd(runPath, sizeof(runPath));
	 printf("[Info]  正在打开示例文件\n");
	 int i;
	 char result;
	 //strcat(runPath, "002.txt");
	 FILE* fp = fopen("test.txt", "r");
	 if (fp!=NULL)
	 {
	 printf("[Success] 文件已加载\n");
	 for (i = 0;; i++)
	 {
		 result= fscanf(fp, "%s      %s	%s	%s  %d %d %d", stu[i].StuId, stu[i].StuName, stu[i].StuGender,
			 stu[i].StuClassIndex,stu[i].StuScore.Math,stu[i].StuScore.English,stu[i].StuScore.Physics);
		 if (result == EOF) break;
	 }
	 fclose(fp);
	 }
	 else
	 {
		 perror("[Error]  文件读取异常:\n"); 

	 }
	 
 }
