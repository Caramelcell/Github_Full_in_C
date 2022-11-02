#include "main.h"

int main(int argc, char* argv[])
{

    ARGS_CHECK(argc, 3)
    //先打开管道1的读端，再打开管道2的写端
    int fdr = open(argv[1],O_RDONLY);
    ERROR_CHECK(fdr,-1,"open")
    int fdw = open(argv[2],O_WRONLY);
    ERROR_CHECK(fdw,-1,"open")
    char buf[128] = {0};
    int ret;

    while(1)
    {
        //先向管道2写入数据
        memset(buf,0,sizeof(buf));
        ret = read(STDIN_FILENO,buf,sizeof(buf));
        ERROR_CHECK(ret,-1,"read")
        ret = write(fdw,buf,strlen(buf)-1); //将read读取的最后的\n给去掉
        ERROR_CHECK(ret,-1,"read")
        //再向管道1读取数据
        memset(buf,0,sizeof(buf));
        ret = read(fdr,buf,sizeof(buf));
        ERROR_CHECK(ret,-1,"read")
        printf("%s\n",buf);
    }
    return 0;
}