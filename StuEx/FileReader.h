// FileReader.h : ���ļ��������ļ���ȡ�๦��


// Copyright (c) Logic.Studio 
// Members:�����Ρ����н���١���
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


//��FileOpen�Ի���ѡ���ļ�
 //����ֵΪ�ļ�·��
 char* OpenFilePicker()
{
    OPENFILENAME open;
    static char file[MAX_PATH]; // ����Ϊ��̬����ȷ���ں������غ�����Ȼ����
    ZeroMemory(&open, sizeof(OPENFILENAME));
    open.lStructSize = sizeof(OPENFILENAME);
    open.lpstrFile = file;
    open.lpstrFile[0] = '\0';
    open.nMaxFile = MAX_PATH;
    open.lpstrFilter = "�ı��ļ�(*.txt)\0*.txt\0�����ļ�(*.*)\0*.*\0\0";
    open.nFilterIndex = 1;
    open.lpstrFileTitle = nullptr;
    open.nMaxFileTitle = 0;
    open.lpstrInitialDir = nullptr;
    open.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    if (GetOpenFileName(&open))
    {
        if (file[0] != '\0') //��������֤
        {
            return file;
        }
    }

    return nullptr; // ���δѡ���κ��ļ��򻺳���Ϊ�գ��򷵻�nullptr
}

 //���ļ��ж�ȡ���ݵ�StudentInfo���͵�������
StudentInfo* ReadDataFile(const char* fileName,StudentInfo stuTemp[])
{
    char result;
    printf("[Info] ���ڴ�ʾ���ļ�\n");
   
    if (fileName != nullptr)//��ַ��Ϊ��
    {
       FILE *fp = fopen(fileName, "a+");
       
        if (fp == nullptr) //ָ�벻Ϊ��
        {
            Color(4);
            perror("[Error] �޷����ļ�");
            Color(7);
          //  return;
        }
        else
        {
            Color(2);
            printf("[Success] �ļ��Ѽ���\n");
            Color(7);
        }
   
        // ��ȡ�ļ�����
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

        // ���¶�λ�ļ�ָ�뵽�ļ�ͷ
        rewind(fp);
        // ���·���洢ѧ����Ϣ��������ڴ�ռ�
        StudentInfo* temp = (StudentInfo*)realloc(stuTemp, stuLength * sizeof(StudentInfo));
        if (temp != NULL)
        {
            stuTemp = temp;
        }
        if (stuTemp == NULL)
        {
            Color(4);
            printf("�ڴ����ʧ��\n");
            fclose(fp);
            Color(7);

        //    return;
        }
        // ���ж�ȡ���ݲ����浽������
        for (int i = 0;; i++)
        {
            result = fscanf(fp, "%s\t%s\t%s\t%s\t%d\t%d\t%d\n", stuTemp[i].StuId, stuTemp[i].StuName, stuTemp[i].StuGender,
                stuTemp[i].StuClassIndex+'\0', &stuTemp[i].StuScore.Math, &stuTemp[i].StuScore.English, &stuTemp[i].StuScore.Physics);
            if (result == EOF) break;
        }
        Color(2);
        printf("[Success] ���ݶ�ȡ�ɹ�\n");
        Color(7);

        // �ر��ļ�
        fclose(fp);
        

        return stuTemp;
    }
    
}

