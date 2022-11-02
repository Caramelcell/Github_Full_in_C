#include "main.h"

int main(int argc, char* argv[])
{

    ARGS_CHECK(argc, 2)
    int fd = open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open")

    printf("\n");   //刷新标准输出
    close(STDOUT_FILENO);
    int fd1 = dup(fd);  //复制一份fd到fd1
    close(fd);
    printf("helloworld\n"); //由于标准输出被关闭，而fd1刚好又复制，fd1就会被放到标准输出的位置，
                            //此时打印就相当于直接把打印的内容写入到argv[1]的文件里，实现文件的重定向

    return 0;
}