#include"HeapSort.h"
void AdjustDown(HPDataType* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		//假设左孩子大，假设错则更新
		if (child + 1 < size && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
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
		if (a[child] > a[parent])
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
void Heapsort(HPDataType* a,int n)
{
	for (int i = 0; i < n; i++)
	{
		AdjustUp(a, i);
	}
	int end = n-1;
	while (end > 0)
	{
		Swap(&a[end],&a[0]);
		AdjustDown(a,end, 0);
		end--;
	}
	return;
}
