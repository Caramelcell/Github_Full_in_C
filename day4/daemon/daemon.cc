#include "main.h"

void Daemon()
{
    if (0 != fork())
    {
        exit(0); //父进程退出
    }
    else
    {
        setsid();                   //脱离原有会话，创建新的会话并成为进程组长,注意进行这一步之后原有的控制终端关闭不能让此进程关闭了
        chdir("/");                 //改变当前工作目录到根目录
        umask(0);                   //掩码
        for (int i = 0; i < 3; i++) //尽可能的关闭从父进程继承来的文件描述符
        {
            close(i);
        }
    }
}

int main(int argc, char *argv[])
{
    ARGS_CHECK(argc, 2)
    Daemon(); //成为守护进程
    int fd;
    fd = open(argv[1], O_RDWR);
    // fflush(stdout);
    // close(STDOUT_FILENO);    //在使用setsid把该守护进程从原有控制终端脱离出去之后该进程的标准输入输出错误输出缓冲区就无效了
    // int fdw = dup(fd);
    // close(fd);
    char buf[128] = "zongzhiquanwangle\n";

    while (1)
    {
        write(fd,buf,strlen(buf));
        // printf("zongzhiquanwangle\n");
        sleep(2);
    }
    close(fd);
    return 0;
}