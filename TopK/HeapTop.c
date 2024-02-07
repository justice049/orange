#include"HeapTop.h"
void Swap(HPDataType* x, HPDataType* y)
{
	HPDataType tmp = *x;
	*x = *y;
	*y = tmp;
}
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (parent - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void AdjustDown(HPDataType* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		//假设左孩子小，假设错则更新
		if (child + 1 < size && a[child + 1] < a[child])
		{
			++child;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = child * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void CreateDate()
{
	// 造数据
	int n = 10000000;
	srand(time(NULL));    //给种子确保真随机
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		int x = (rand() + i) % 10000000;
		fprintf(fin,"%d\n",x);     //写文件
	}
	fclose(fin);
}
void PrintTopK(const char* file,int k)
{
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen error");
		return;
	}
	int* minHeap = (int*)malloc(sizeof(int) * k);
	if (minHeap == NULL)
	{
		perror("malloc fail");
		return;
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &minHeap[i]);     //读文件
		AdjustUp(minHeap,i);      //建小堆
	}
	int x = 0;
	while (fscanf(fout,"%d", &x)!=EOF)    //将值读取到变量X中
	{
		if (x > minHeap[0])
		{
			minHeap[0] = x;
			AdjustDown(minHeap, k, 0);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", minHeap[i]);
	}
	printf("\n");
	return;
}
	