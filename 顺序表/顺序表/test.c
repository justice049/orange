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
	printf("****** 1.尾插 *** 2.尾删 ******\n");
	printf("****** 3.头插 *** 4.头删 ******\n");
	printf("****** 5.查找 *** 6.打印 ******\n");
	printf("****** 7.指定位置插入 *********\n");
	printf("****** 8.指定位置删除 *********\n");
	printf("****** 9.排序 *** 0.退出 ******\n");
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
			printf("请输入你要插入的位置：\n");
			scanf("%d", &n);
			printf("请输入你要插入的数：\n");
			scanf("%d", &m);
			SLInsert(&sl, n, m);
			break;
		}
		case 8:
		{
			int n = 0;
			printf("请输入你要删除的位置：\n");
			scanf("%d", &n);
			SLErase(&sl, n);
			break;
		}
		case 9:
		{
			break;
		}
			
		default:
			printf("请输入有效的操作数\n");
			break;
		}
	} while (n);
	SLDestroy(&sl);
	return 0;
}
//数组下标从零开始，逻辑自洽
//arr[i]==*(a+i);
//arr[0]=*(a+0);