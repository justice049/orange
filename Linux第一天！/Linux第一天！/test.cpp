//#include<stdio.h>
//int main(int argc,char* argv[])
//{
//
//	return 0;
//}



//#include<stdio.h>
//#include<unistd.h>
////#include<string.h>
//int g_val = 100000;
//int main()
//{
//    /#include<stdio.h>
//#include<unistd.h>
////#include<string.h>
//    pid_t id = fork();
//    if (id == 0)
//    {
//        while (1)
//        {
//            printf("I am child process,pid: %d,ppid: %d , g_val: %d\n", getpid(),getppid(), g_val);
//            sleep(1);
//        }
//    }
//    else
//    {
//        while (1)
//        {
//            printf("I am father process,pid: %d,ppid: %d , g_val: %d\n", getpid(), getppid(), g_val);
//            sleep(1);
//        }
//    }
//    return 0;
//}
#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(int argc, char* argv[])
{
    printf("I am father process,pid: %d,ppid: %d , g_val: %d\n", getpid(), getppid(), g_val);
    if (argc != 2)
    {
        printf("Usage:%s -[a,b,c,d]\n", argv[0]);
        return 1;
    }
    if (strcmp(argv[1], "-a") == 0)
    {
        printf("this is function1\n");
    }
    else if (strcmp(argv[1], "-b") == 0)
    {
        printf("this is function2\n");
    }
    else if (strcmp(argv[1], "-c") == 0)
    {
        printf("this is function3\n");
    }
    else if (strcmp(argv[1], "-d") == 0)
    {
        printf("this is function4\n");
    }
    else
    { 
        printf("no this function!\n");
    }
    return 0;
}
