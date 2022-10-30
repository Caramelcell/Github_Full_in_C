#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int index;
	char sex;
	char name[20];
}stu;

void print(int* arr);

int main(int argc,char* argv[])
{
	if(3 != argc)
	{
		printf("argc error\n");
		return -1;
	}

	int i = atoi(argv[1]);
	int j = atoi(argv[2]);
	int arr[5] = {1,2,3,4,5};
	char infoStu[100] = {0};
	stu s = {100,'f',"lele"};
	stu ts = {0};
//	j = i / 0;

//	for(i = 0;i < 5;i++)
//	{
//		print(&arr[i]);
//	}

	sprintf(infoStu,"%d%c%s",s.index,s.sex,s.name);
	sscanf(infoStu,"%d%c %s",&ts.index,&ts.sex,ts.name);

	return 0;
}
