//#include<stdio.h>
//#include<unistd.h>
//int main()
//{
//	extern char** environ;   //ÉùÃ÷Ò»¹þ
//	int i = 0;
//	for (i = 0; environ[i]; i++)
//	{
//		printf("env[%d]->%s\n", i, environ[i]);
//	}
//	return 0;
//}



//#include<stdio.h>
//#include<unistd.h>
//#include<stdlib.h>
//int main(int argc,char* argv[],char* env[])
//{
//	char* path = getenv("PATH");
//	if (path == NULL)
//	{
//		return 1;
//	}
//	printf("path:%d\n", path);
//
//	return 0;
//}




#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int  g_val = 100;

int main()
{
	printf("father is running,pid: %d,ppid: %d\n", getpid(), getppid());

	pid_t id = fork();
	if (id == 0)
	{
		//child
		int cnt = 0;
		while (1)
		{
			printf("I am child process,pid: %d,ppid: %d\n", getpid(), getppid());
			printf("g_val: %d,&g_val: %d\n", g_val, &g_val);
			sleep(1);
			cnt++;
			if (cnt == 5)
			{
				g_val = 300;
				printf("I am child process,change:%d -> %d\n", 100, 300);
			}
		}
	}
	else
	{
		//father
		while (1)
		{
			printf("I am father process,pid: %d,ppid: %d\n", getpid(), getppid());
			printf("g_val: %d,&g_val: %d\n", g_val, &g_val);
			sleep(1);
		}
	}
	return 0;
}