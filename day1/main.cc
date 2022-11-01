#include "optdir.h"

int main(int argc, char* argv[])
{
    ARGS_CHECK(argc,2)

    //depthprint(argv[1],0);
    statprint(argv[1]); //不知道为什么这个main只能对当前目录进行状态打印，
                        //stat函数走到上一级目录就出现了错误，可能是进程地址空间的问题，仍待解决

    return 0;
}