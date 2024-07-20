#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
#include"task.h"

typedef void(*func_t)();

#define N 3
func_t tasks[N] = { NULL };

void LoadTask()
{
	tasks[0] = Printlog;
	tasks[1] = Download;
	tasks[2] = MysqlDataSync;
}

void HanderTask()
{
	for (int i = 0; i < N; i++)
	{
		tasks[i]();
	}
}

void DoOtherThing()
{
	HanderTask();
}

void ChildRun()
{
	int cnt = 5;
	while (cnt)
	{
		printf("I am child process,pid:%d,ppid:%d,cnt:%d\n", getpid(), getppid(), cnt);
		cnt--;
		sleep(1);
	}
}

int main()
{
	printf("I am father process,pid:%d,pid:%d\n", getpid(), getppid());

	pid_t id = fork();
	if (id == 0)
	{
		ChildRun();
		printf("child quit\n");
		exit(123);
	}
	LoadTask();
	while (1)
	{
		int status = 0;
		pid_t rid = waitpid(id, &status, WNOHANG);	//进行非阻塞等待
		if (rid == 0)
		{
			printf("child is running, father check next time!\n");
			//DoOtherThing();
		}
		else if (rid > 0)
		{
			if (WIFEXITED(status))
			{
				printf("child quit success,child exit code:%d\n", WEXITSTATUS(status));
			}
			else
			{
				printf("child quit unnormal!\n");
			}
			break;
		}
		else
		{
			printf("waitpid failed!\n");
			break;
		}
	}
	return 0;
}