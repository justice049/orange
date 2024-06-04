//#include<stdio.h>
//#include<unistd.h>
//#include<sys/types.h>
//#include<unistd.h>
//
//int main()
//{
//    printf("process is running,only me!,pid:%d\n", getpid());
//    sleep(3);
//    pid_t id = fork();
//    if (id == -1) return 1;
//    else if (id == 0)
//    {
//        //child
//        while (1)
//        {
//            printf("id:%d,I am child process, pid: % d, ppid : % d\n",id,getpid(),getppid());
//                sleep(1);
//        }
//
//    }
//    else
//    {
//        //parent
//        while (1)
//        {
//            printf("id:%d,I am parent process,pid:%d,ppid:%d\n", getpid(), getppid());
//            sleep(2);
//        }
//
//    }
//    return 0;
//}
//#include<stdio.h>
//#include<unistd.h>
//#include<sys/types.h>
//#include<unistd.h>
//
//void RunChild()
//{
//    while (1)
//    {
//        printf("I am parent, pid :%d,ppid: %d\n", getpid(), getppid());
//        sleep(1);
//    }
//}
//int main()
//{
//    const int num = 5;
//    int i = 0;
//    for (i = 0; i < num; i++)
//    {
//        pid_t id = fork();
//        if (id == 0)      //因为父进程的id不等于0，所以直接跳过判断执行下次循环，创建紫禁城
//        {
//            RunChild();
//        }
//        sleep(1);
//    }
//    while (1)
//    {
//        sleep(1);
//        printf("I am parent, pid :%d,ppid: %d\n", getpid(), getppid());
//    }
//    return 0;
//}
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    pid_t id = getpid();
    pid_t parent = getppid();
    while (1)
    {
        printf("I am a process!,pid:%d ,ppid:%d\n", id, parent);
        sleep(1);
    }
    return 0;
}
