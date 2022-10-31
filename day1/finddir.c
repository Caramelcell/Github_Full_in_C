#include "finddir.h"

int find_dir(char* path, const char* dirname, int wid)
{
    DIR* dir;
    struct dirent *ptr;
    off_t pos;

    dir = opendir(path);
    DIR_CHECK(dir, opendir)
    while(NULL != (ptr = readdir(dir)))
    {
        if((strcmp(ptr->d_name,".")) || (strcmp(ptr->d_name,".."))) //
        {
            //do nothing
        }
        else if(4 == ptr->d_type)  //is directory
        {
            printf("%*s%s",wid)
            memset(buf, 0, sizeof(char));
            sprintf(buf, "%s%s%s", dirname, '/', ptr->d_name);
            find_dir(dir,buf);
        }
        else if(0 == strcmp(ptr->d_name,dirname))
        {
            pos = telldir(dir); //find it
        }
    }
}

int main(int argc, char* argv[], const char* dirname)
{
    ARGS_CHECK(argc,3)
    DIR* dir;

    dir = opendir(argv[1]);
    DIR_CHECK(dir,"opendir")
    struct dirent *ptr;
    off_t pos;
    while((ptr = readdir(dir)))
    {
        printf("inod=%ld,len=%d,type=%d,name=%s\n",ptr->d_ino,ptr->d_reclen,ptr->d_type,ptr->d_name);
        if(0 == strcmp(ptr->d_name,dirname))
        {
            pos = telldir(dir);
        }
    }
    seekdir(dir,pos);
    printf("inod=%ld,len=%d,type=%d,name=%s\n",ptr->d_ino,ptr->d_reclen,ptr->d_type,ptr->d_name);

    closedir(dir);
    return 0;
}
