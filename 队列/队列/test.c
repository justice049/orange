#include"Queue.h"
int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	int size = QueueSize(&q);
	printf("%d\n", size);
	int head = QueueFront(&q);
	printf("%d\n", head);
	int tail = QueueBack(&q);
	printf("%d\n", tail);
	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	QueueDestroy(&q);
	return 0;
}