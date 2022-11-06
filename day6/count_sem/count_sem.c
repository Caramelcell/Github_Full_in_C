#include "main.h"

#define MAX 1000000

/*2022/11/6 有点似懂非懂，总的来说，我理解的商品与货架是这样的关系，生产者与消费者的pv操作自身就存在着一把锁，
    生产者生产时，当剩余货架空了，无法再进行p操作减少货架，信号量1号无法再减少，就产生了阻塞，进入睡眠状态，
    而此时消费者仍然在跑，所以当此时消费者进行p操作时(商品为空，不可能产生阻塞，只有商品为空时p操作才会产生阻塞)
    商品会减少一个，这时锁就体现了作用，消费者没有进行v操作，剩余货架不会增多，生产者就不会被唤醒从而对货架进行操作，
    当消费者完成消费，将剩余货架增加1个时，生产者才会被唤醒，而此时消费者已经完成了一轮pv操作，所以不存在生产者和消费者
    同时对着空货架进行操作的情况，而在生产者消费者都在跑的情况下(指两个进程都没有睡觉)，不管对信号量0号和信号量1号做出了什么样的操作
    进行一个pv周期后，总的数目不会乱掉，因为pv操作是操作系统层面的原子操作，商品加一，货架就一定会减一//有点难得理解，
    互斥与并发也是似懂非懂的，就先这样吧，明天开始就开始为期一周的C语言复习，然后把编译器做出来，没有思路就先把题目做一下，over*/
int main()
{
    int shmid, i, semid, ret;

    // semaphory
    semid = semget(1000, 2, IPC_CREAT | 0600); //创建一个信号量集合，包含两个信号量，0号信号量代表商品，1号信号量代表空闲货架
    ERROR_CHECK(semid, -1, "semget");
    unsigned short arr[2] = {0, 10};     // arr[0]代表商品，arr[1]代表空闲货架
    ret = semctl(semid, 0, SETALL, arr); //初始化信号量的值
    ERROR_CHECK(ret, -1, "semctl");

    if (0 == fork())
    {
        for (i = 0; i < MAX; i++)
        {
            struct sembuf sopp, sopv; // PV操作
            sopp.sem_num = 0;         //商品
            sopp.sem_op = -1;
            sopp.sem_flg = SEM_UNDO;
            sopv.sem_num = 1; //空位
            sopv.sem_op = 1;
            sopv.sem_flg = SEM_UNDO;
            printf("I'm consumer,goods num is %d,empty shelves num is %d\n", semctl(semid, 0, GETVAL), semctl(semid, 1, GETVAL));
            semop(semid, &sopp, 1); //购买一个商品
            printf("shoping\n");
            semop(semid, &sopv, 1); //空闲货架增加一个
            printf("I'm consumer,goods num is %d,empty shelves num is %d\n", semctl(semid, 0, GETVAL), semctl(semid, 1, GETVAL));
            sleep(2);
        }
        return 0;
    }
    else
    {
        for (i = 0; i < MAX; i++)
        {
            struct sembuf sopp, sopv; // PV操作
            sopp.sem_num = 1;         //空位
            sopp.sem_op = -1;
            sopp.sem_flg = SEM_UNDO;
            sopv.sem_num = 0; //商品
            sopv.sem_op = 1;
            sopv.sem_flg = SEM_UNDO;
            printf("I'm producer,goods num is %d,empty shelves num is %d\n", semctl(semid, 0, GETVAL), semctl(semid, 1, GETVAL));
            semop(semid, &sopp, 1); //生产，空闲货架减少一个
            printf("producing\n");
            semop(semid, &sopv, 1); //商品数量增加一个
            printf("I'm producer,goods num is %d,empty shelves num is %d\n", semctl(semid, 0, GETVAL), semctl(semid, 1, GETVAL));
            sleep(1);
        }
        wait(NULL);
        // ret = shmctl(shmid,IPC_RMID,NULL);   //删除共享内存,命令ipcrm -m id
        // ERROR_CHECK(shmid, -1, "shmctl");
        // ret = semctl(semid,0,IPC_RMID);      //删除信号量集合,命令ipcrm -s id
        // ERROR_CHECK(semid, -1, "semctl");
        return 0;
    }
}