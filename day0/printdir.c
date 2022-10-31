#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

#define ARGS_CHECK(argc,num) {if(argc != num) {printf("error args\n"); return -1;}}
#define ERROR_CHECK(ret,func_name) {if(0 != ret) {perror(func_name); return -1;}}
#define DIR_CHECK(dir,func_name) {if(NULL == dir) {perror(func_name); return -1;}}

int main(int argc, char* argv[])
{
    ARGS_CHECK(argc,2);
    DIR* dir;
    dir = opendir(argv[1]);
//    if(NULL == dir)
//    {
//        perror("opendir");
//       return -1;
//    }
    DIR_CHECK(dir,"opendir");
    struct dirent *ptr;
    while((ptr = readdir(dir)))
    {
        printf("inod=%ld,len=%d,type=%d,name=%s\n",ptr->d_ino,ptr->d_reclen,ptr->d_type,ptr->d_name);
    }
    closedir(dir);
    return 0;
}
