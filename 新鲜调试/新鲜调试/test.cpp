#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include<conio.h>
#include<assert.h>
//�ṹ�嶨��
typedef struct _student
{
    char name[20] = { 0 };         //ѧ������
    int xuehao = 0;                  //ѧ��
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

void welcome();                   //�˵�����
void input(Node* head);           //��������
void del(Node* head);             //ɾ������
void find(Node* head);            //��������
void change(Node* head);          //�޸�����
void Printf(Node* head);          //��ӡ����
void count(Node* head);           //ͳ������
void bubble(Node* head);          //����


void input(Node* head)
{
    FILE* fp = fopen("test.txt", "a+");             //׷�Ӳ�������,�ɳ�����չ
    if (fp == NULL)
    {
        perror("touch fail");
        return;
    }
    Node* fresh = (Node*)malloc(sizeof(Node));
    if (fresh == NULL)
    {
        perror("malloc fail");
        return;
    }
    Node* move = head;

    fputs("����:", fp);
    printf("������:\n");
    printf("ѧ��������:\n");
    scanf("%s", fresh->student.name);             //����
    fprintf(fp, "%s\n", fresh->student.name);      //���ļ�������
    //�����Դ�����

    fputs("�Ա�:", fp);
    printf("ѧ���Ա�:");
    scanf("%s", fresh->student.gender);
    fprintf(fp, "%s", fresh->student.gender);

    fputs("ѧ��:", fp);
    printf("ѧ��ѧ��:");
    scanf("%d", &fresh->student.xuehao);
    fprintf(fp, "%d", &fresh->student.xuehao);

    fputs("���:", fp);
    printf("ѧ�����:");
    scanf("%d", &fresh->student.height);
    fprintf(fp, "%d", &fresh->student.height);

    fputs("����:", fp);
    printf("ѧ������:");
    scanf("%d", &fresh->student.height);
    fprintf(fp, "%d", &fresh->student.weight);

    fputs("�绰:", fp);
    printf("ѧ���绰:");
    scanf("%s", fresh->student.tel);
    fprintf(fp, "%s", fresh->student.tel);

    fclose(fp);               //�ر��ļ���ֹ��ʧ����
    fp = NULL;
    return;

    while (move->next)
    {
        move = move->next;
    }
    move->next = fresh;           //β��һ��
    fresh->next = NULL;
    printf("�������\n");

   
}
int main()
{
    Node* head = (Node*)malloc(sizeof(Node));
    if (head == NULL)
    {
        perror("malloc fail");
        return 0;
        head->next = NULL;
    }
    input(head);
    head->next = NULL;
    return 0;
}