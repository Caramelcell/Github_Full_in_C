#include "optdir.h"

int depthprint(char *path, int wid)
{
    DIR *dir;
    struct dirent *ptr;
    char cur_path[1024];
    off_t pos = 0;

    dir = opendir(path);
    DIR_CHECK(dir, "opendir")
    while (ptr = readdir(dir))
    {
        if (!strcmp(ptr->d_name, ".") || !strcmp(ptr->d_name, "..")) //读取到.和..文件时不打印
        {
            // do nothing
        }
        else
        {
            printf("%*s%s\n", wid, "", ptr->d_name);
            if (4 == ptr->d_type)
            {
                sprintf(cur_path, "%s%s%s", path, "/", ptr->d_name);
                depthprint(cur_path, wid + 2);
            }
            if (0 == strcmp(ptr->d_name, "depthprint.h"))
            {
                pos = telldir(dir);
            }
        }
    }

    if (0 != pos)
    {
        seekdir(dir, pos);
        ptr = readdir(dir);
        printf("I get it : %s\n", ptr->d_name);
    }

    closedir(dir);
    return 0;
}

int get_rwx(unsigned int mode_temp, char *mod)
{
    switch (mode_temp)
    {
    case 7:
        strcpy(mod, "rwx");
        break;
    case 6:
        strcpy(mod, "rw-");
        break;
    case 5:
        strcpy(mod, "r-x");
        break;
    case 4:
        strcpy(mod, "r--");
        break;
    case 3:
        strcpy(mod, "-wx");
        break;
    case 2:
        strcpy(mod, "-w-");
        break;
    case 1:
        strcpy(mod, "--x");
        break;
    case 0:
        strcpy(mod, "---");
        break;
    default:
        return -1;
    }
    return 0;
}

int statprint(char *path)
{
    DIR *dir;
    dir = opendir(path);
    DIR_CHECK(dir, "opendir")
    struct stat buf;
    struct dirent *ptr;
    int ret, i, j;
    unsigned int mode_temp;
    char *timetemp;
    char timebuf[30] = {0};
    unsigned int x[4] = {61400, 448, 56, 7};
    unsigned int y[4] = {12, 6, 3, 0};
    //char cur_path[1024];

    while ((ptr = readdir(dir)))
    {
        char mode[11] = {0};
        char mod[4] = {0};

        ret = stat(ptr->d_name, &buf);
        ERROR_CHECK(ret, "stat")
        timetemp = ctime(&buf.st_mtime);
        for (i = 0, j = 0; i < strlen(timetemp); i++)
        {
            if (i >= 4 && i <= 15)
            {
                timebuf[j++] = timetemp[i];
            }
        }
        //把ctime返回的字符串里面的星期，秒数，年份以及最后的\n给去掉

        for (i = 0; i < 4; i++)
        {
            mode_temp = (buf.st_mode & x[i]) >> y[i];
            if (0 == i)
            {
                if (4 == mode_temp)
                {
                    mode[0] = 'd';
                }
                else
                {
                    mode[0] = '-';
                }
            }
            else
            {
                get_rwx(mode_temp, mod);
                strcat(mode, mod);
            }
        }
        //分离出当前文件的状态信息转换成rwx形式

        printf("%7ld %s %ld %s %s %6ld %s %s\n",
               buf.st_ino, mode, buf.st_nlink,
               getpwuid(buf.st_uid)->pw_name, getgrgid(buf.st_gid)->gr_name,
               buf.st_size, timebuf, ptr->d_name);
    }
    closedir(dir);
    return 0;
}