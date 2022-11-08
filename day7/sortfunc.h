
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SWAP(a,b) {int t;t=a;a=b;b=t;}

void print(const int* arr, int len);
int check(const int* arr, int len);
void bubble(int* arr, int len);
void select(int* arr, int len);
void insert(int* arr, int len);
void merge(int* arr, int left, int right);
void quick(int* arr, int left, int right);
void maxheap(int* arr, int len, int point);
void heap(int* arr, int len);