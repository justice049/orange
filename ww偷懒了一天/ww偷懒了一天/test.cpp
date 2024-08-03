#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

const char* filename = "log.txt";

int main()
{
	printf("hello printf\n");
	fprintf(stdout, "hello fprintf\n");

	const char* msg = "hello write\n";
	write(1, msg, strlen(msg));

	fork();
	return 0;
}