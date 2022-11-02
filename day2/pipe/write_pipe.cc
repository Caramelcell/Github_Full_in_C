#include "main.h"

int main(int argc, char* argv[])
{

    ARGS_CHECK(argc, 3)
    //先打开管道1的写端，再打开管道2的读端
    int fdw = open(argv[1],O_WRONLY);
    ERROR_CHECK(fdw,-1,"open")
    int fdr = open(argv[2],O_RDONLY);
    ERROR_CHECK(fdr,-1,"open")
    char buf[128] = {0};
    int ret;

    while(1)
    {
        //先向管道2读取数据
        memset(buf,0,sizeof(buf));
        ret = read(fdr,buf,sizeof(buf));
        ERROR_CHECK(ret,-1,"read")
        printf("%s\n",buf);
        //再向管道1写入数据
        memset(buf,0,sizeof(buf));
        ret = read(STDIN_FILENO,buf,sizeof(buf));
        ERROR_CHECK(ret,-1,"read")
        ret = write(fdw,buf,strlen(buf)-1); //将read读取的最后的\n给去掉
        ERROR_CHECK(ret,-1,"read")
    }
    return 0;
}