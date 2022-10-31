#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#define ARGS_CHECK(argc,num) {if(argc != num) {printf("error args\n"); return -1;}}
#define ERROR_CHECK(ret,func_name) {if(0 != ret) {perror(func_name); return -1;}}
#define DIR_CHECK(dir,func_name) {if(NULL == dir) {perror(func_name); return -1;}}

int find_dir(char* path, const char* dirname, int wid);