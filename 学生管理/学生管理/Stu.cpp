#include"Stu.h"

//�洢����(��)
void input(Node* head)
{
    FILE* fp = fopen("data.txt", "a+");             //׷�Ӳ�������,�ɳ�����չ
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
        if (move == NULL)
        {
            printf("�Ҳ�����ѧ��\n");
            return;
        }
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
        scanf("%d", &move->student.number);
        break;
    }
    case 4:
    {
        printf("��������Ҫ�����:");
        scanf("%d", &move->student.height);
        break;
    }
    case 5:
    {
        printf("��������Ҫ������:");
        scanf("%d", &move->student.weight);
        break;
    }
    case 6:
    {
        printf("��������Ҫ�ĵ绰:");
        scanf("%s", move->student.tel);
        break;
    }
    default:
    {
        printf("�������\n");
        break;
    }
    printf("�޸����\n");
    return;
    }
}


//��
void find(Node* head)
{
    Node* move = head;
    int number = 0;
    printf("������������Ҫѧ����Ϣ��ѧ��\n");
    scanf("%d", &number);
    assert(move->next);
    while (move->student.number != number)
    {
        move = move->next;
        if (move == NULL)
        {
            printf("�Ҳ�����ѧ��\n");
            return;
        }
    }
    printf("��Ѱ��ѧ������ϢΪ:\n����:%s\tѧ��:%d\n", move->student.name, move->student.number);
    printf("�Ա�:%s\t���:%d\t����:%d\n", move->student.gender, move->student.height, move->student.weight);
    printf("�绰:%s\n", move->student.tel);
    return;
}


//����
int count(Node* head)
{
    assert(head);
    int count = 0;
    Node* move = head->next;
    while (move != NULL)
    {
        count++;
        move = move->next;
    }
    return count;
}


//��ӡ
void Printf(Node* head)
{
    Node* cur = head;
    if (cur == NULL)
    {
        printf("ͷָ��Ϊ��");
        return;
    }

    while (cur)
    {
        cur = cur->next;
        printf("����:%s  ѧ��:%d  ", cur->student.name, cur->student.number);
        printf("�Ա�:%s  ���:%d  ����:%d  ", cur->student.gender, cur->student.height, cur->student.weight);
        printf("�绰:%s\n", cur->student.tel);
        if (cur->next == NULL)
        {
            return;
        }
    }
    return;
}

void Swapdata(int* a, int* b)        //��������
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

int* Quick_Sort(Node* pBegin,Node* pEnd)
{
    if (pBegin == NULL || pEnd == NULL || pBegin == pEnd)
    {
        return 0;
    }

    //��������ָ��
    Node* p1 = pBegin;
    Node* p2 = pBegin->next;
    int pivot = pBegin->student.number;

    //ÿ��ֻ�Ƚ�С�ģ���С�ķ���ǰ��
    // ����һ�ֱȽϺ󣬱��ֳ�����������
    // ����p1ָ����ֵ����pbeginΪpivot
    while (p2 != NULL)                 //&& p2 != pEnd->next 
    {
        if (p2->student.number < pivot)
        {
            p1 = p1->next;
            if (p1 != p2)
            {
                Swapdata(&p1->student.number, &p2->student.number);
            }
        }
        p2 = p2->next;
    }
    //��ʱpivot�������м䣬Ҫ�����ŵ��м䣬����Ϊ��׼�������ݷ�Ϊ��������
    Swapdata(&p1->student.number, &pBegin->student.number);
    //��ʱp1����ֵ�ڵ�
    //if(p1->data >pBegin->data)
    Quick_Sort(pBegin, p1);
    //if(p1->data < pEnd->data)
    Quick_Sort(p1->next, pEnd);
}

//��ӡ��ʷ����
void PrintfVictory(Node* head, int x)
{
    FILE* fp = fopen("data.txt", "r+");
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