#define _CRT_SECURE_NO_WARNINGS
#ifndef M_H_
#define M_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define ERROR_CHECK(ret,error,funcname) {if(error == ret) {perror(funcname); return -1;}}
#define ARGS_CHECK(argc,num) {if(argc != num) {printf("error args\n"); return -1;}}
#define SWAP(a,b) {int t;t=a;a=b;b=t;}

#endif // !M_H_

int printIntArr(const int* arr, int len);
int qsortCompare12(const void* num1, const void* num2);
int qsortCompare21(const void* num1, const void* num2);
int Question1();
int Question2();
int Question3();
int Question4();
int Question5();
int Question6();
int Question7();
int Question8();
int Question9();
int Question10();
int Question11();
int Question12();
int Question13();
int Question14();
int Question15();
int Question16();
int Question17();
int Question18();
int Question19();
int Question20();
int Question21();
int Question22();
int Question23();
int Question24();
int Question25();
int Question26();
int Question27();
int Question28();
int Question29();
int Question30();