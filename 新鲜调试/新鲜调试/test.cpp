#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include<conio.h>
#include<assert.h>
//结构体定义
typedef struct _student
{
    char name[20] = { 0 };         //学生姓名
    int xuehao = 0;                  //学号
    char gender[20] = { 0 };       //性别
    char tel[20] = { 0 };          //电话号
    int height = 0;                //身高
    int weight = 0;                //体重
} student;

//定义结点,方便修改数据
typedef struct _Node
{
    student student;
    struct _Node* next;
} Node;

void welcome();                   //菜单界面
void input(Node* head);           //输入数据
void del(Node* head);             //删除数据
void find(Node* head);            //查找数据
void change(Node* head);          //修改数据
void Printf(Node* head);          //打印数据
void count(Node* head);           //统计人数
void bubble(Node* head);          //排序


void input(Node* head)
{
    FILE* fp = fopen("test.txt", "a+");             //追加插入数据,可持续发展
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

    fputs("姓名:", fp);
    printf("请输入:\n");
    printf("学生的姓名:\n");
    scanf("%s", fresh->student.name);             //输入
    fprintf(fp, "%s\n", fresh->student.name);      //向文件中输入
    //下面以此类推

    fputs("性别:", fp);
    printf("学生性别:");
    scanf("%s", fresh->student.gender);
    fprintf(fp, "%s", fresh->student.gender);

    fputs("学号:", fp);
    printf("学生学号:");
    scanf("%d", &fresh->student.xuehao);
    fprintf(fp, "%d", &fresh->student.xuehao);

    fputs("身高:", fp);
    printf("学生身高:");
    scanf("%d", &fresh->student.height);
    fprintf(fp, "%d", &fresh->student.height);

    fputs("体重:", fp);
    printf("学生体重:");
    scanf("%d", &fresh->student.height);
    fprintf(fp, "%d", &fresh->student.weight);

    fputs("电话:", fp);
    printf("学生电话:");
    scanf("%s", fresh->student.tel);
    fprintf(fp, "%s", fresh->student.tel);

    fclose(fp);               //关闭文件防止丢失数据
    fp = NULL;
    return;

    while (move->next)
    {
        move = move->next;
    }
    move->next = fresh;           //尾插一下
    fresh->next = NULL;
    printf("输入完成\n");

   
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