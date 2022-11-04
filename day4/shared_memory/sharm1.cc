#include "main.h"

int main()
{
    key_t key = 1000;
    int size = 4096;
    int shmid;
    char* add;

    shmid = shmget(key,size,IPC_CREAT|0600);
    printf("%d\n",shmid);
    ERROR_CHECK(shmid,-1,"shmget");
    //创建4k大小的共享内存
    add = (char*)shmat(shmid,NULL,0);
    ERROR_CHECK(add,(char*)-1,"shmat");
    //映射该共享内存
    strcpy(add,"Hao are you");
    return 0;
}