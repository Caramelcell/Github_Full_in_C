#include "main.h"

int inQue(pNode* rear, pNode* front, int data)
{
	pNode pnew = (pNode)malloc(sizeof(node));
	pnew->data = data;
	pnew->next = NULL;
	if (*rear == NULL)
	{
		*rear = pnew;
		(*rear)->next = pnew;
		*front = pnew;
	}
	else {
		(*rear)->next = pnew;
		*rear = pnew;
		(*rear)->next = *front;
	}
	return 0;
}
int outQue(pNode* rear, pNode* front)
{
	if (*front == NULL)
	{
		printf("queue is empty!\n");
	}
	else if (*front == *rear) {	//ѭ������ֻ��һ���ڵ�
		printf("%3d ", (*front)->data);
		free(*front);
		*front = NULL;
		*rear = NULL;
	}
	else {
		printf("%3d ", (*front)->data);
		*front = (*front)->next;
		free((*rear)->next);
		(*rear)->next = *front;
	}
	return 0;
}
int Question30()
{
	pNode front, rear;	//��front��,rear��
	front = NULL;
	rear = NULL;
	int n, k, m, i, ret;
	ret = scanf("%d%d%d", &n, &k, &m);
	for (i = 1; i <= n; i++)
	{
		inQue(&rear, &front, i);	//���
		printf("%3d ", rear->data);
	}
	printf("\n------------------------------------------\n");
	for (i = 1; i < k; i++)	//�ӱ��Ϊk���˿�ʼ
	{
		rear = rear->next;
		front = front->next;
	}
	while (front)
	{
		for (i = 1; i < m; i++)	//����m���˳���
		{
			rear = rear->next;
			front = front->next;
		}
		outQue(&rear, &front);
	}
	printf("\n");
	return 0;
}