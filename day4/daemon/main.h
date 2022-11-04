#ifndef MAIN_H_
#define MAIN_H_

    #include <iostream>
    #include <cstring>
    #include <ctime>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <dirent.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <pwd.h>
    #include <grp.h>
    #include <sys/select.h>
    #include <sys/time.h>
    #include <sys/wait.h>

    #define ARGS_CHECK(argc,num) {if(argc != num) {printf("error args\n"); return -1;}}
    #define ERROR_CHECK(ret,error,func_name) {if(error == ret) {perror(func_name); return -1;}}

#endif //MAIN_H_