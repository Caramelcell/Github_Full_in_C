#include "main.h"

int main()
{
    key_t key = 1000;
    int size = 4096;
    int shmid;
    char* add;

    shmid = shmget(key,size,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmget");
    //创建or打开4k大小的共享内存
    add = (char*)shmat(shmid,NULL,0);
    ERROR_CHECK(add,(char*)-1,"shmat");
    //映射该共享内存
    char buf[1024] = {0};
    strcpy(buf,add);
    puts(buf);
    shmctl(shmid,IPC_RMID,NULL);

    return 0;
}