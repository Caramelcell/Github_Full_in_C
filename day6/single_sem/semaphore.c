#include "main.h"

#define MAX 1000000

int main()
{
    int shmid, i, semid, ret;
    int *p;

    // share memory
    shmid = shmget(1000, 4096, IPC_CREAT | 0600);
    ERROR_CHECK(shmid, -1, "shmget");
    p = shmat(shmid, NULL, 0);
    ERROR_CHECK((char *)p, (char *)-1, "shmat");
    p[0] = 0;

    // semaphory
    semid = semget(1000, 1, IPC_CREAT | 0600); //创建一个信号量集合
    ERROR_CHECK(semid, -1, "semget");
    ret = semctl(semid, 0, SETVAL, 1); //初始化信号量的值为1
    ERROR_CHECK(ret, -1, "semctl");
    struct sembuf sopp, sopv; // PV操作及对应的信号量编号
    sopp.sem_num = 0;         //操作的是第0个信号量
    sopp.sem_op = -1;
    sopp.sem_flg = SEM_UNDO;
    sopv.sem_num = 0;
    sopv.sem_op = 1;
    sopv.sem_flg = SEM_UNDO;

    if (0 == fork())
    {
        for (i = 0; i < MAX; i++)
        {
            semop(semid, &sopp, 1); //上锁，是操作系统层面的原子操作，比较耗时
            p[0]++;
            semop(semid, &sopv, 1); //解锁
        }
        return 0;
    }
    else
    {
        for (i = 0; i < MAX; i++)
        {
            semop(semid, &sopp, 1); //上锁
            p[0]++;
            semop(semid, &sopv, 1); //解锁
        }
        wait(NULL);
        printf("%d\n", p[0]);
        // ret = shmctl(shmid,IPC_RMID,NULL);   //删除共享内存,命令ipcrm -m id
        // ERROR_CHECK(shmid, -1, "shmctl");
        // ret = semctl(semid,0,IPC_RMID);      //删除信号量集合,命令ipcrm -s id
        // ERROR_CHECK(semid, -1, "semctl");
        return 0;
    }
}