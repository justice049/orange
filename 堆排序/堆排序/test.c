#include"HeapSort.h"
int main()
{
	int arr[9] = { 1,5,6,9,7,4,2,3,8 };
	Heapsort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}