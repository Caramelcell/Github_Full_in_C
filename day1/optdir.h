#ifndef D_H_
#define D_H_

    #include <iostream>
    #include <cstring>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <dirent.h>
    #include <unistd.h>
    #include <ctime>
    #include <pwd.h>
    #include <grp.h>

    #define ARGS_CHECK(argc,num) {if(argc != num) {printf("error args\n"); return -1;}}
    #define ERROR_CHECK(ret,func_name) {if(0 != ret) {perror(func_name); return -1;}}
    #define DIR_CHECK(dir,func_name) {if(NULL == dir) {perror(func_name); return -1;}}

    int depthprint(char* path, int wid);
    int get_rwx(unsigned int mode_temp, char* mod);
    int statprint(char* path);

#endif //D_H_