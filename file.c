#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define ONE 1
#define TWO (1<<1)
#define THREE (1<<2)
#define FOUR (1<<3)

void Print(int flag)
{
	if (flag && ONE)
	{
		printf("one\n");
	}

}

int main()
{
	umask(0);
	int fd = open("log.txt", O_WRONLY | O_CREAT, 0666);
	if (fd < 0)
	{
		perror("open fail");
		return 1;
	}
	return 0;
}
