#include"Stu.h"
//存储数据(增)
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
    fprintf(fp, "%s\t", fresh->student.name);      //向文件中输入
    //下面以此类推

    fputs("性别:", fp);
    printf("学生性别:");
    scanf("%s", fresh->student.gender);
    fprintf(fp, "%s\t", fresh->student.gender);

    fputs("学号:", fp);
    printf("学生学号:");
    scanf("%d", &fresh->student.number);
    fprintf(fp, "%d\t", fresh->student.number);

    fputs("身高:", fp);
    printf("学生身高:");
    scanf("%d", &fresh->student.height);
    fprintf(fp, "%d\t", fresh->student.height);

    fputs("体重:", fp);
    printf("学生体重:");
    scanf("%d", &fresh->student.weight);
    fprintf(fp, "%d\t", fresh->student.weight);

    fputs("电话:", fp);
    printf("学生电话:");
    scanf("%s", fresh->student.tel);
    fprintf(fp, "%s\n", fresh->student.tel);

    while (move->next)
    {
        move = move->next;
    }
    move->next = fresh;           //尾插一下
    fresh->next = NULL;
    printf("输入完成\n");

    fclose(fp);               //关闭文件防止丢失数据
    fp = NULL;
    return;
}

//删除数据(删)
void del(Node* head)
{
    Node* move = head;
    Node* pre = head;
    int number = 0;
    printf("请输入您需要删除学生的学号；\n");
    scanf("%d", &number);
    while (move->student.number != number)
    {
        pre = move;
        move = move->next;
    }
    pre->next = move->next;
    free(move);
    move = NULL;              //及时置空防止野指针
    printf("删除成功\n");
}

//修改(改)
void menu()
{
    printf("请输入需要修改的内容:\n");
    printf("1.姓名  2.性别  3.学号\n");
    printf("4.身高  5.体重  6.电话\n");
}

void change(Node* head)
{
    int number;
    Node* move = head;
    printf("请输入您所需要修改学生的学号:\n");
    scanf("%d", &number);
    while (move->student.number != number)
    {
        move = move->next;
    }
    menu();
    int i = 0;
    scanf("%d", &i);
    switch (i)
    {
    case 1:
    {
        printf("请输入需要的姓名:");
        scanf("%s", move->student.name);
        break;
    }
    case 2:
    {
        printf("请输入需要的性别:");
        scanf("%s", move->student.gender);
        break;
    }
    case 3:
    {
        printf("请输入需要的学号:");
        scanf("%d", move->student.number);
        break;
    }
    case 4:
    {
        printf("请输入需要的身高:");
        scanf("%d", move->student.height);
        break;
    }
    case 5:
    {
        printf("请输入需要的体重:");
        scanf("%d", move->student.weight);
        break;
    }
    case 6:
    {
        printf("请输入需要的电话:");
        scanf("%d", move->student.tel);
        break;
    }
    default:
    {
        printf("输入错误，请重新输入:\n");
        break;
    }
    printf("修改完成\n");
    return;

    }

    void Printf(Node * head)
    {
        Node* cur = head;
        if (cur == NULL)
        {
            printf("NULL\n");
            return;
        }
        while (cur->next != NULL)
        {
            printf("%s  ", cur->student.name);
            printf("%s  ", cur->student.gender);
            printf("%d  ", cur->student.number);
            printf("%d  ", cur->student.height);
            printf("%d  ", cur->student.weight);
            printf("%s\n", cur->student.tel);
            cur = cur->next;
        }
        return;
    }

    //查找(查)
    void find(Node * head)
    {
        Node* move = head;
        int xuehao;
        printf("请输入您所需要学生信息的学号\n");
        scanf("%d", &xuehao);
        assert(move->next);
        while (move->student.number != xuehao)
        {
            move = move->next;
        }
        printf("您寻找学生的信息为:\n姓名:%s\t学号:%d\n", move->student.name, move->student.number);
        printf("性别:%s\t身高:%d\t体重:%d\n", move->student.gender, move->student.height, move->student.weight);
        printf("电话:%d", move->student.tel);
        return;
    }

    //打印历史数据
    void PrintfVictory(Node * head, int x)
    {
        FILE* fp = fopen("test.txt", "r+");
        if (fp == NULL)
        {
            perror("touch fail");
            return;
        }
        Node* move = head;
        char str[20] = { 0 };
        while (x--)
        {
            fscanf(fp, "%s", str);
            printf("%s  ", str);

            fscanf(fp, "%s", str);
            printf("%s  ", str);

            fscanf(fp, "%s", str);
            printf("%s  ", str);

            fscanf(fp, "%s", str);
            printf("%s  ", str);

            fscanf(fp, "%s", str);
            printf("%s  ", str);

            fscanf(fp, "%s", str);
            printf("%s\n", str);

        }
        fclose(fp);
        fp = NULL;
        return;
    }

    //打印

    //计数
    int count(Node * head)
    {
        assert(head);
        int count = 0;
        Node* move = head->next;
        while (move != NULL)
        {
            count++;
            move = move->next;
        }
        printf("学生人数为:%d\n", count);
        return count;
    }

    //排序
    void bubble(Node * head)
    {
        assert(head);
        int count = 0;
        Node* move = head->next;
        while (move != NULL)
        {
            count++;
            move = move->next;
        }
        Node* live = head;
        Node* die = head;
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < count - i; j++)
            {
                if (live->student.number > live->next->student.number)
                {
                    int tmp = live->student.number;
                    live->student.number = live->next->student.number;
                    live->next->student.number = tmp;
                }
            }
        }
        while (count)
        {
            printf("%d %s", die->student.number, die->student.name);
            die = die->next;
        }
    }
