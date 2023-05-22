
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
    static char file[MAX_PATH]; // Declared as static to ensure it persists after the function returns
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
        if (file[0] != '\0') // Validate the buffer
        {
            return file;
        }
    }

    return nullptr; // Return nullptr if no file was selected or buffer is empty
}


StudentInfo* ReadDataFile(const char* fileName,StudentInfo stuTemp[])
{
    char result;
    
    printf("[Info] 正在打开示例文件\n");
   
    if (fileName != nullptr)//地址不为空
    {
       FILE *fp = fopen(fileName, "a+");
       
        if (fp == nullptr) //指针不为空
        {
            perror("[Error] 无法打开文件");
          //  return;
        }
        else
        {
            printf("[Success] 文件已加载\n");
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
            printf("内存分配失败\n");
            fclose(fp);
        //    return;
        }
        // 逐行读取数据并保存到数组中
        for (int i = 0;; i++)
        {
            result = fscanf(fp, "%s\t%s\t%s\t%s\t%d\t%d\t%d\n", stuTemp[i].StuId, stuTemp[i].StuName, stuTemp[i].StuGender,
                stuTemp[i].StuClassIndex+'\0', &stuTemp[i].StuScore.Math, &stuTemp[i].StuScore.English, &stuTemp[i].StuScore.Physics);
            if (result == EOF) break;
        }
        printf("[Success] 数据读取成功\n");
        
        // 关闭文件
        fclose(fp);
        

        return stuTemp;
    }
    
}

