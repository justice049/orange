#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

#define SIZE 512

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
	const char* cwd = getenv["PWD"];
	if (cwd == NULL)
	{
		return "None";
	}
	return cwd;
}

void MakeCommandLine(char line[], size_t size)
{

}

int main()
{
	// ‰≥ˆ√¸¡Ó––
	char commandline[SIZE];
	MakeCommandLine(commandline,sizeof(commandline));
	/*printf("name:%s", getusername());
	printf("%s", gethostname());
	printf("%s", gethostname());*/

	return 0;
}