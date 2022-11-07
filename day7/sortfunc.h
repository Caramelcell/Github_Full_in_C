
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SWAP(a,b) {int t;t=a;a=b;b=t;}

void print(const int* arr, int len);
int check(const int* arr, int len);
void bubble(int* arr, int len);
void select(int* arr, int len);
void insert(int* arr, int len);
void order_merge(int* arr, int left, int mid, int right);
void merge(int* arr, int left, int right);