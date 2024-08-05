#include"mystdio.h"
#include<stdio.h>
#include<unistd.h>
#include<string.h>

#define FILE_NAME "log.txt"

int main()
{
	myFILE* fp = my_fopen(FILE_NAME,"w");
	if (fp == NULL)
	{
		return 1;
	}

	const char* str = "hello world";

	int cnt = 10;
	char buffer[128];
	while (cnt)
	{
		sprintf(buffer, "%s - %d\n", str, cnt);
		my_fwrite(fp, buffer, strlen(buffer));
		cnt--;
	}

	my_fclose(fp);
	return 0;
}