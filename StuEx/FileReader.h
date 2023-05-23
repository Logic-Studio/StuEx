// FileReader.h : 此文件定义了文件读取类功能


// Copyright (c) Logic.Studio 
// Members:刘明鑫、刘承锦、佟雨锟
// SPDX-License-Identifier: MIT Lisense

#include "UI.h"
#include <cstdio>
#include "GlobalVar.h"
#include <windows.h>
#include <ShlObj.h>
#include <stdio.h>
#include <stdlib.h>
#include <atlstr.h> 
#include <fileapi.h>


//打开FileOpen对话框，选择文件
 //返回值为文件路径
 char* OpenFilePicker()
{
    OPENFILENAME open;
    static char file[MAX_PATH]; // 声明为静态，以确保在函数返回后它仍然存在
    ZeroMemory(&open, sizeof(OPENFILENAME));
    open.lStructSize = sizeof(OPENFILENAME);
    open.lpstrFile = file;
    open.lpstrFile[0] = '\0';
    open.nMaxFile = MAX_PATH;
    open.lpstrFilter = "文本文件(*.txt)\0*.txt\0所有文件(*.*)\0*.*\0\0";
    open.nFilterIndex = 1;
    open.lpstrFileTitle = nullptr;
    open.nMaxFileTitle = 0;
    open.lpstrInitialDir = nullptr;
    open.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    if (GetOpenFileName(&open))
    {
        if (file[0] != '\0') //缓冲区验证
        {
            return file;
        }
    }

    return nullptr; // 如果未选择任何文件或缓冲区为空，则返回nullptr
}

 //从文件中读取数据到StudentInfo类型的数组中
StudentInfo* ReadDataFile(const char* fileName,StudentInfo stuTemp[])
{
    char result;
    printf("[Info] 正在打开示例文件\n");
   
    if (fileName != nullptr)//地址不为空
    {
       FILE *fp = fopen(fileName, "a+");
       
        if (fp == nullptr) //指针不为空
        {
            Color(4);
            perror("[Error] 无法打开文件");
            Color(7);
          //  return;
        }
        else
        {
            Color(2);
            printf("[Success] 文件已加载\n");
            Color(7);
        }
   
        // 获取文件行数
        int prevChar = '\n';
        int currChar;

        while ((currChar = fgetc(fp)) != EOF) {
            if (currChar == '\n') {
                stuLength++;
            }
            else if (currChar == '\r' && prevChar != '\n') {
                stuLength++;
            }

            prevChar = currChar;
        }

        // 重新定位文件指针到文件头
        rewind(fp);
        // 重新分配存储学生信息的数组的内存空间
        StudentInfo* temp = (StudentInfo*)realloc(stuTemp, stuLength * sizeof(StudentInfo));
        if (temp != NULL)
        {
            stuTemp = temp;
        }
        if (stuTemp == NULL)
        {
            Color(4);
            printf("内存分配失败\n");
            fclose(fp);
            Color(7);

        //    return;
        }
        // 逐行读取数据并保存到数组中
        for (int i = 0;; i++)
        {
            result = fscanf(fp, "%s\t%s\t%s\t%s\t%d\t%d\t%d\n", stuTemp[i].StuId, stuTemp[i].StuName, stuTemp[i].StuGender,
                stuTemp[i].StuClassIndex+'\0', &stuTemp[i].StuScore.Math, &stuTemp[i].StuScore.English, &stuTemp[i].StuScore.Physics);
            if (result == EOF) break;
        }
        Color(2);
        printf("[Success] 数据读取成功\n");
        Color(7);

        // 关闭文件
        fclose(fp);
        

        return stuTemp;
    }
    
}

