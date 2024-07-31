//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	FILE* fp = fopen("myfile", "w");
//	if (!fp)
//	{
//		printf("fopen error!\n");
//	}
//	const char* msg = "hello world!\n";
//	int count = 5;
//	while (count--)
//	{
//		fwrite(msg, strlen(msg), 1, fp);
//	}
//	fclose(fp);
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<fstream>
//
//#define FILENAME "log.txt"
//
//int main()
//{
//	std::ofstream out(FILENAME, std::ios::binary);
//	if (!out.is_open())
//	{
//		return 1;
//	}
//	
//	std::string message = "hello C++\n";
//
//	out.write(message.c_str(), message.size());
//	out.close();
//	return 0;
//}



//#include<stdio.h>
//#include<sys/types.h>
//#include<sys/stat.h>
//#include<fcntl.h>
//
//#define ONE 1
//#define TWO (1<<1)
//#define THREE (1<<2)
//#define FOUR (1<<3)
//
//void Print(int flag)
//{
//	if (flag & ONE)
//	{
//		printf("one\n");
//	}
//	if (flag & TWO)
//	{
//		printf("two\n");
//	}
//	if (flag & THREE)
//	{
//		printf("three\n");
//	}
//	if (flag & FOUR)
//	{
//		printf("four\n");
//	}
//}
//int main()
//{
//	Print(ONE);
//	printf("\n");
//	Print(ONE | TWO);
//	printf("\n");
//	Print(ONE | TWO | THREE);
//	printf("\n");
//	Print(ONE | TWO | THREE | FOUR);
//	printf("\n");
//	return 0;
//}


//#include<stdio.h>
//#include<string.h>
//#include<unistd.h>
//#include<sys/types.h>
//#include<sys/stat.h>
//#include<fcntl.h>
//int main()
//{
//	umask(0);
//	int fd = open("log.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
//	if (fd < 0)
//	{
//		perror("open fail");
//		return 1;
//	}
//
//	const char* message = "Hello Linux file\n";
//	write(fd, message, strlen(message));
//	close(fd);
//	return 0;
//}




//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	FILE* fp = fopen("myfile", "r");
//	if (!fp)
//	{
//		printf("fopen error!\n");
//	}
//	char buf[1024];
//	const char* msg = "hello world!\n";
//	while (1)
//	{
//		size_t s = fread(buf, 1, strlen(msg), fp);
//		if (s > 0)
//		{
//			buf[s] = 0;
//			printf("%s", buf);
//		}
//		if (feof(fp))
//		{
//			break;
//		}
//	}
//	fclose(fp);
//	return 0;
//}



//#include<stdio.h>
//#include<string.h>
//int main()
//{
	//const char* msg = "hello fwrite\n";
	//fwrite(msg, strlen(msg), 1, stdout);
//
//	printf("hello printf\n");
//	fprintf(stdout, "hello fprintf\n");
//	return 0;
//}


#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	const char* msg = "hello pineapple\n";
	write(1,msg,strlen(msg));
	return 0;
}


//int main()
//{
//	int fda = open("loga.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
//	printf("fda:%d\n", fda);
//	int fdb = open("logb.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
//	printf("fdb:%d\n", fdb);
//	int fdc = open("logc.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
//	printf("fdc:%d\n", fdc);
//	int fdd = open("logd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
//	printf("fdd:%d\n", fdd);
//	return 0;
//}