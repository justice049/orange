#include"SeqList.h"
void Test1()
{
	SL s;
	Init(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPrint(&s);
	printf("\n");
	SLPushFront(&s, 1);
	SLPushFront(&s, 2);
	SLPushFront(&s, 3);
	SLPrint(&s);
	SLPopBack(&s);
	SLPrint(&s);
	SLErase(&s, 1);
	SLErase(&s, 1);
	SLPrint(&s);
	printf("%d", SLFind(&s, 3));
	SLDestroy(&s);
}
void menu()
{
	printf("*******************************\n");
	printf("****** 1.β�� *** 2.βɾ ******\n");
	printf("****** 3.ͷ�� *** 4.ͷɾ ******\n");
	printf("****** 5.���� *** 6.��ӡ ******\n");
	printf("****** 7.ָ��λ�ò��� *********\n");
	printf("****** 8.ָ��λ��ɾ�� *********\n");
	printf("****** 9.���� *** 0.�˳� ******\n");
	printf("*******************************\n");
}
int main()
{
	int n = 1;
	SL sl;
	Init(&sl);
	do
	{
		scanf("%d", &n);
		switch (n)
		{
		case 1:
		{
			SLDataType n = 0;
			scanf("%d", &n);
			SLPushBack(&sl, n);
			break;
		}
		case 2:
		{
			SLPopBack(&sl);
			break;
		}
		case 3:
		{
			SLDataType n = 0;
			scanf("%d", &n);
			SLPushFront(&sl,n);
			break;
		}
		case 4:
		{
			SLPopFront(&sl);
			break;
		}
		case 5:
		{
			int n = 0;
			scanf("%d", &n);
			SLFind(&sl,n);
			break;
		}
		case 6:
		{
			SLPrint(&sl);
			break;
		}
		case 7:
		{
			int n = 0;
			int m = 0;
			printf("��������Ҫ�����λ�ã�\n");
			scanf("%d", &n);
			printf("��������Ҫ���������\n");
			scanf("%d", &m);
			SLInsert(&sl, n, m);
			break;
		}
		case 8:
		{
			int n = 0;
			printf("��������Ҫɾ����λ�ã�\n");
			scanf("%d", &n);
			SLErase(&sl, n);
			break;
		}
		case 9:
		{
			break;
		}
			
		default:
			printf("��������Ч�Ĳ�����\n");
			break;
		}
	} while (n);
	SLDestroy(&sl);
	return 0;
}
//�����±���㿪ʼ���߼���Ǣ
//arr[i]==*(a+i);
//arr[0]=*(a+0);