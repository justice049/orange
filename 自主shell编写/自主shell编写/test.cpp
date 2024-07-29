#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<errno.h>
#include<sys/wait.h>
#define SkipPath(p) do{ \
p = strlen(p) - 1; \
while (*p != '/')
{
	p--;
}
}while(0)

#define SIZE 512
#define ZERO '\0'
#define SEP " "
#define NUM 32

char cwd[SIZE * 2];
char* gArgv[NUM];

void Die()
{
	exit(1);
}

const char* Home()
{
	const char* home = getenv("HOME");
	if (home == NULL)
	{
		return "/";
	}
	return home;
}

void Cd()
{
	const char* path = gArgv[1];
	if (path == NULL)
	{
		path = Home();
	}
	chdir(path);

	char temp[SIZE * 2];
	getcwd(temp, sizeof(temp));
	sprintf(cwd, sizeof(cwd), "PWD=%s", temp);
	putenv(cwd);
}

const char* GetUserName()
{
	const char* name = getenv("USER");
	if (name == NULL)
	{
		return "None";
	}
	return name;
}

const char* GetHostName()
{
	const char* hostname = getenv("HOSTNAME");
	if (hostname == NULL)
	{
		return "None";
	}
	return hostname;
}

const char* GetCwd()
{
	const char* cwd = getenv("PWD");
	if (cwd == NULL)
	{
		return "None";
	}
	return cwd;
}

void MakeCommandLine()
{
	char line[SIZE];
	const char* username = GetUserName();
	const char* hostname = GetHostName();
	const char* cwd = GetCwd();
	snprintf(line, sizeof(line), "[%s@%s %s]#", username, hostname, cwd);
	printf("%s", line);
	fflush(stdout);
}

int GetUserCommand(char command[], size_t n)
{
	char* s = fgets(command, n, stdin);
	if (s == NULL)
	{
		return -1;
	}
	command[strlen(command) - 1] = ZERO;
	return strlen(command);
}


void splitCommand(char command[], size_t n)
{
	gArgv[0] = strtok(command, SEP);
	int index = 1;
	while ((gArgv[index++] = strtok(NULL, SEP)));
}

void ExecuteCommand()
{
	pid_t id = fork();
	if (id < 0)
	{
		Die();
	}
	else if (id == 0)
	{
		execvp(gArgv[0], gArgv);
		exit(errno);
	}
	else
	{
		int status = 0;
		pid_t rid = waitpid(id, &status, 0);
		if (rid > 0)
		{

		}
	}
}

int CheckBuildin()
{
	int yes = 0;
	const char* enter_cmd = gArgv[0];
	if (strcmp(enter_cmd, "cd") == 0)
	{
		yes = 1;
		Cd();
	}
	return yes;
}

int main()
{
	int quit = 0;
	while (!quit)
	{
		MakeCommandLine();

		char usercommand[SIZE];
		int n = GetUserCommand(usercommand, sizeof(usercommand));
		if (n < 0)
		{
			return 1;
		}

		splitCommand(usercommand, sizeof(usercommand));

		n = CheckBuildin();
		if (n)
		{
			continue;
		}

		ExecuteCommand();
	}
	return 0;
}