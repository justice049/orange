#include"Heap.h"
int main()
{
	int arr[10] = { 1,5,6,3,2,4,8,9,7 };
	Heap(arr, 9);
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}