#include "main.h"

int main(int argc, char *argv[])
{
    ARGS_CHECK(argc, 3)
    //打开管道1的读端
    int fdr = open(argv[1], O_RDONLY);
    ERROR_CHECK(fdr, -1, "open")
    //打开管道2的写端
    int fdw = open(argv[2], O_WRONLY);
    ERROR_CHECK(fdw, -1, "open")
    //存放从标准输入缓冲区和管道读端读取的数据
    char buf[128] = {0};
    int ret;
    //使用select监听标准输入缓冲区和管道读端
    fd_set rdset;

    while (1)
    {
        FD_ZERO(&rdset);
        FD_SET(STDIN_FILENO, &rdset); //监听标准输入缓冲区，有数据代表可向管道2写内容
        FD_SET(fdr, &rdset);          //监听管道1读端，有数据代表可读
        ret = select(fdr + 1, &rdset, NULL, NULL, NULL);
        ERROR_CHECK(ret, -1, "select")

        if (FD_ISSET(STDIN_FILENO, &rdset)) // FD_ISSET有数据返回真
        {
            memset(buf, 0, sizeof(buf));
            ret = read(STDIN_FILENO, buf, sizeof(buf));
            ERROR_CHECK(ret, -1, "read")
            if (0 == ret) //读端主动断开ctrl+d
            {
                printf("I want to leave\n");
                break;
            }
            ret = write(fdw, buf, strlen(buf) - 1); //将read读取的最后的\n给去掉
            ERROR_CHECK(ret, -1, "write")
        }
        if (FD_ISSET(fdr, &rdset)) //注意此时写端断开时管道的读端就会一直是可读状态
                                   //即read会一直返回0
        {
            memset(buf, 0, sizeof(buf));
            ret = read(fdr, buf, sizeof(buf));
            ERROR_CHECK(ret, -1, "read")
            if (0 == ret) //说明写端断开了
            {
                printf("byebye\n");
                break;
            }
            printf("%s\n", buf);
        }
    }
    close(fdr);
    close(fdw);
    return 0;
}