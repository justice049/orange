#include"Heap.h"
int main()
{
	int arr[] = { 4,6,2,1,5,8,2,9 };
	HP hp;
	HeapInit(&hp);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		HeapPush(&hp, arr[i]);
	}
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", hp.a[i]);
	}
	printf("\n");
	int k = 3;
	while (k>0)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
		k--;
	}
	printf("\n");
	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	printf("\n");
	return 0;
}