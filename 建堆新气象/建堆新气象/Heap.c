#include"Heap.h"
void Swap(HPDataType* x, HPDataType* y)
{
	HPDataType tmp = *x;
	*x = *y;
	*y = tmp;
}
void AdjustDown(HPDataType* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
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
void Heap(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)  //从最后一个非叶子结点开始向下调整
	{
		AdjustDown(a, n, i);
	}
	return;
}