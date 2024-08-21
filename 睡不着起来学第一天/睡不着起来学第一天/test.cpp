//#include<stdio.h>
//int main()
//{
//    int a = 0;
//    scanf("%d", &a);
//    printf("%d", a);
//    return 0;
//}
#define KEY_BOARD 1
#define SCREEN 2
struct device
{
	int type;
	int status;
	//ÆäËûÊôĞÔ
	struct device* next;
	task_struct* wait_queue;
};