//struct q
//{
//	int nr_active;
//	bitmap[5];
//	queue[140];
//};

//#include <unistd.h>
//pid_t fork(void);
//int main(void)
//{
//	pid_t pid;
//
//	printf("Before: pid is %d\n", getpid());
//	if ((pid = fork()) == -1)
//		perror("fork()"), exit(1);
//	printf("After:pid is %d, fork return %d\n", getpid(), pid);
//	sleep(1);
//	return 0;
//}

#include<stdio.h>
#include<unistd.h>
#include<string.h>

//自定义枚举常量
enum
{
	Success = 0,
	Div_Zero,
	Mod_Zero,
};

int exit_code = Success;

const char* CodeToErrString(int code)
{
	switch (code)
	{
		case Success:
			return "Success";
		case Div_Zero:
			return "div zero!";
		case Mod_Zero:
			return "mod zero!";
		default:
			return "unknow error!";
	}
}

int Div(int x, int y)
{
	if (0 == y)
	{
		exit_code = Div_Zero;
		return -1;
	}
	else
	{
		return x / y;
	}
}
int main()
{
	printf("%d\n", Div(-1, 1));
	printf("%s\n", CodeToErrString(exit_code));
	return exit_code;
}
//int main()
//{
//	int errcode = 0;
//	for (errcode = 0; errcode <= 255; errcode++)
//	{
//		printf("%d:%s\n", errcode, strerror(errcode));
//	}
//	return 0;
//}