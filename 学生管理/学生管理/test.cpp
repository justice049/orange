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
            printf("ѧ������Ϊ:%d\n", nu);
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
            printf("��ӭ�´�ʹ��\n");
            if (head == NULL)
            {
                exit(0);
            }
            while (head)
            {
                Node* del = head;
                head = head->next;
                free(del);          //�ͷſռ�
            }
            head = NULL;   //ָ�뼰ʱ�ÿշ�ֹҰָ�����
            return 0;
        }
        default:
        {
            printf("������Ĺ��ܲ�����\n");
            system("pause");
            system("cls");
            break;
        }
        }
    }
    return 0;
}

//�˵�
void welcome()
{
    printf("----------------------------\n");
    printf("********ѧ������ϵͳ********\n\n");
    printf("����1---����ѧ����Ϣ\t\t\n");
    printf("����2---��ӡѧ����Ϣ\t\t\n");
    printf("����3---ͳ��ѧ������\t\t\n");
    printf("����4---����ѧ����Ϣ\t\t\n");
    printf("����5---�޸�ѧ����Ϣ\t\t\n");
    printf("����6---ɾ��ѧ����Ϣ\t\t\n");
    printf("����7---����ѧ����Ϣ\t\t\n");
    printf("����0---�˳�����\t\t\n");
    printf("----------------------------\n");
    printf("������������Ҫ���ܶ�Ӧ������\n");
}

//��¼�˶Խ���
void passwd()
{
    char ch[20] = { 0 };
    char str[20] = "justice";
    printf("�������ļ����룺");
    while (1)
    {
        scanf("%s", ch);
        if (strcmp(ch, str) != 0)
        {
            printf("������������²���\n");
        }
        else
        {
            printf("������ȷ\n");
            break;
        }
    }
}