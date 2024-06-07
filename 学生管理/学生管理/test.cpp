#include"Stu.h"
int main()
{
    passwd();
    Node* head = (Node*)malloc(sizeof(Node));
    if (head == NULL)
    {
        perror("malloc fail");
        return 0;
        head->next = NULL;
    }
    head->next = NULL;

    while (1)
    {
        welcome();
        int c = 0;
        scanf("%d", &c);
        switch (c)
        {
        case 1:
        {
            input(head);
            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
            Printf(head);
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            int nu = count(head);
            printf("学生人数为:%d\n", nu);
            system("pause");
            system("cls");
            break;
        }
        case 4:
        {
            find(head);
            system("pause");
            system("cls");
            break;
        }
        case 5:
        {
            change(head);
            system("pause");
            system("cls");
            break;
        }
        case 6:
        {
            del(head);
            system("pause");
            system("cls");
            break;
        }
        case 7:
        {
            Node* pEnd = head;
            while (pEnd->next)
            {
                pEnd = pEnd->next;
            }
            Quick_Sort(head,pEnd);
            Printf(head);
            system("pause");
            system("cls");
            break;
        }
        case 8:
        {
            PrintfVictory(head,10);
            system("pause");
            system("cls");
            break;
        }
        case 0:
        {
            printf("欢迎下次使用\n");
            if (head == NULL)
            {
                exit(0);
            }
            while (head)
            {
                Node* del = head;
                head = head->next;
                free(del);          //释放空间
            }
            head = NULL;   //指针及时置空防止野指针出现
            return 0;
        }
        default:
        {
            printf("你输入的功能不存在\n");
            system("pause");
            system("cls");
            break;
        }
        }
    }
    return 0;
}

//菜单
void welcome()
{
    printf("----------------------------\n");
    printf("********学生管理系统********\n\n");
    printf("输入1---输入学生信息\t\t\n");
    printf("输入2---打印学生信息\t\t\n");
    printf("输入3---统计学生人数\t\t\n");
    printf("输入4---查找学生信息\t\t\n");
    printf("输入5---修改学生信息\t\t\n");
    printf("输入6---删除学生信息\t\t\n");
    printf("输入7---整理学生信息\t\t\n");
    printf("输入0---退出程序\t\t\n");
    printf("----------------------------\n");
    printf("请输入您所需要功能对应的数字\n");
}

//登录核对界面
void passwd()
{
    char ch[20] = { 0 };
    char str[20] = "justice";
    printf("请输入文件密码：");
    while (1)
    {
        scanf("%s", ch);
        if (strcmp(ch, str) != 0)
        {
            printf("密码错误，请重新操作\n");
        }
        else
        {
            printf("密码正确\n");
            break;
        }
    }
}