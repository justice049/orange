#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include<conio.h>
#include<assert.h>
#include<string.h>
#include<Windows.h>
//�ṹ�嶨��
//����ǳǳֱ�ӳ�ʼ��һ�°ɣ�����������
typedef struct _student
{
    char name[20] = { 0 };         //ѧ������
    int number = 0;                //ѧ��
    char gender[20] = { 0 };       //�Ա�
    char tel[20] = { 0 };          //�绰��
    int height = 0;                //���
    int weight = 0;                //����
} student;

//������,�����޸�����
typedef struct _Node
{
    student student;
    struct _Node* next;
} Node;

void passwd();                            //��¼����
void welcome();                           //�˵�����

void input(Node* head);                   //��������
void del(Node* head);                     //ɾ������
void change(Node* head);                  //�޸�����
void find(Node* head);                    //��������

void Printf(Node* head);                  //��ӡ����

int count(Node* head);                    //ͳ������

int* Quick_Sort(Node* pBegin, Node* pEnd);               //����
void PrintfVictory(Node* head, int x);