#include"mymath.h"
#include"mystdio.h"
#include<stdio.h>
#include<string.h>

int main()
{
	int a = 10;
	int b = 20;
	printf("%d+%d=%d\n", a, b, myAdd(a, b));

	myFILE* fp = my_fopen("./myfile.txt", "w");
	if (fp == NULL)
	{
		return 1;
	}

	const char* message = "要不要出去玩...\n";
	my_fwrite(fp, message, strlen(message));

	my_fclose(fp);
	return 0;
}