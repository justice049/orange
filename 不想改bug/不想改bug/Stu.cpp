#include"Stu.h"
//�洢����(��)
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
    fprintf(fp, "%s\t", fresh->student.name);      //���ļ�������
    //�����Դ�����

    fputs("�Ա�:", fp);
    printf("ѧ���Ա�:");
    scanf("%s", fresh->student.gender);
    fprintf(fp, "%s\t", fresh->student.gender);

    fputs("ѧ��:", fp);
    printf("ѧ��ѧ��:");
    scanf("%d", &fresh->student.number);
    fprintf(fp, "%d\t", fresh->student.number);

    fputs("���:", fp);
    printf("ѧ�����:");
    scanf("%d", &fresh->student.height);
    fprintf(fp, "%d\t", fresh->student.height);

    fputs("����:", fp);
    printf("ѧ������:");
    scanf("%d", &fresh->student.weight);
    fprintf(fp, "%d\t", fresh->student.weight);

    fputs("�绰:", fp);
    printf("ѧ���绰:");
    scanf("%s", fresh->student.tel);
    fprintf(fp, "%s\n", fresh->student.tel);

    while (move->next)
    {
        move = move->next;
    }
    move->next = fresh;           //β��һ��
    fresh->next = NULL;
    printf("�������\n");

    fclose(fp);               //�ر��ļ���ֹ��ʧ����
    fp = NULL;
    return;
}

//ɾ������(ɾ)
void del(Node* head)
{
    Node* move = head;
    Node* pre = head;
    int number = 0;
    printf("����������Ҫɾ��ѧ����ѧ�ţ�\n");
    scanf("%d", &number);
    while (move->student.number != number)
    {
        pre = move;
        move = move->next;
    }
    pre->next = move->next;
    free(move);
    move = NULL;              //��ʱ�ÿշ�ֹҰָ��
    printf("ɾ���ɹ�\n");
}

//�޸�(��)
void menu()
{
    printf("��������Ҫ�޸ĵ�����:\n");
    printf("1.����  2.�Ա�  3.ѧ��\n");
    printf("4.���  5.����  6.�绰\n");
}

void change(Node* head)
{
    int number;
    Node* move = head;
    printf("������������Ҫ�޸�ѧ����ѧ��:\n");
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
        printf("��������Ҫ������:");
        scanf("%s", move->student.name);
        break;
    }
    case 2:
    {
        printf("��������Ҫ���Ա�:");
        scanf("%s", move->student.gender);
        break;
    }
    case 3:
    {
        printf("��������Ҫ��ѧ��:");
        scanf("%d", move->student.number);
        break;
    }
    case 4:
    {
        printf("��������Ҫ�����:");
        scanf("%d", move->student.height);
        break;
    }
    case 5:
    {
        printf("��������Ҫ������:");
        scanf("%d", move->student.weight);
        break;
    }
    case 6:
    {
        printf("��������Ҫ�ĵ绰:");
        scanf("%d", move->student.tel);
        break;
    }
    default:
    {
        printf("�����������������:\n");
        break;
    }
    printf("�޸����\n");
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

    //����(��)
    void find(Node * head)
    {
        Node* move = head;
        int xuehao;
        printf("������������Ҫѧ����Ϣ��ѧ��\n");
        scanf("%d", &xuehao);
        assert(move->next);
        while (move->student.number != xuehao)
        {
            move = move->next;
        }
        printf("��Ѱ��ѧ������ϢΪ:\n����:%s\tѧ��:%d\n", move->student.name, move->student.number);
        printf("�Ա�:%s\t���:%d\t����:%d\n", move->student.gender, move->student.height, move->student.weight);
        printf("�绰:%d", move->student.tel);
        return;
    }

    //��ӡ��ʷ����
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

    //��ӡ

    //����
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
        printf("ѧ������Ϊ:%d\n", count);
        return count;
    }

    //����
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
