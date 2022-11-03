#include "main.h"

int main(int argc, char *argv[])
{

    ARGS_CHECK(argc, 1)
    pid_t pid;
    int status;

    pid = fork();

    // if(0 == pid)    //子进程
    // {
    //     printf("I am son,fathers pid=%d,my pid=%d\n",getppid(),getpid());
    //     while(1);   //子进程先于父进程结束且父进程没有进行回收，则子进程变为僵尸进程
    // }else{          //父进程
    //     printf("I am father,fathers pid=%d,my pid=%d\n",getppid(),getpid());
    //     while(1);   //父进程先于子进程结束，则子进程变为孤儿进程
    // }

    if(0 == pid)    //子进程
    {
        execl("./add","add","3","4",NULL);
    }else{          //父进程
        pid = wait(&status);
        printf("my son process pid is %d return_val is %d\n",pid,WEXITSTATUS(status));
    }

    return 0;
}