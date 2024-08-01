//#include<stdio.h>
//#include<string.h>
//#include<unistd.h>
//#include<sys/types.h>
//#include<sys/stat.h>
//#include<fcntl.h>
//
//int main()
//{
//	printf("stdin->fd:%d\n", stdin->_fileno);
//	printf("stdout->fd:%d\n", stdout->_fileno);
//	printf("stderr->fd:%d\n", stderr->_fileno);
//
//	FILE* fp = fopen("log.txt", "w");
//	if (fp == NULL)
//	{
//		return 1;
//	}
//	printf("fd:%d\n", fp->_fileno);
//	
//	FILE* fp1 = fopen("log1.txt", "w");
//	if (fp1 == NULL)
//	{
//		return 1;
//	}
//	printf("fd:%d\n", fp1->_fileno);
//	
//	FILE* fp2 = fopen("log2.txt", "w");
//	if (fp2 == NULL)
//	{
//		return 1;
//	}
//	printf("fd:%d\n", fp2->_fileno);
//
//	fclose(fp);
//	return 0;
//}



//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<unistd.h>
//#include<sys/types.h>
//#include<sys/stat.h>
//#include<fcntl.h>
//
//const char* filename = "log.txt";
//
//int main()
//{
//	struct stat st;
//	int n = stat(filename, &st);
//	if (n < 0)
//	{
//		return 1;
//	}
//
//	printf("file size:%lu\n", st.st_size);
//	int fd = open(filename, O_RDONLY);
//	
//	if (fd < 0)
//	{
//		perror("open fail");
//		return 2;
//	}
//	printf("fd:%d\n", fd);
//
//	char* file_buffer = (char*)malloc(st.st_size + 1);
//	
//	n = read(fd, file_buffer, st.st_size);
//	if (n > 0)
//	{
//		file_buffer[n] = '\0';
//		printf("%s\n", file_buffer);
//	}
//	free(file_buffer);
//	close(fd);
//	return 0;
//}



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

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

//int main()
//{
//	int fd = open("/dev/pts/2", O_CREAT | O_WRONLY | O_TRUNC, 0666);
//
//	if (fd < 0)
//	{
//		perror("open fail\n");
//		return 1;
//	}
//
//	dup2(fd, 1);
//
//	printf("hello world\n");
//	fprintf(stdout, "hello world\n");
//
//	fflush(stdout);
//	return 0;
//}
