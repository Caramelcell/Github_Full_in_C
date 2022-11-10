#include "main.h"

int Question27(pNode head, int data)
{
	pNode pcur, ppre;
	pcur = ppre = head;
	while (pcur != NULL)
	{
		if (pcur->data != data)
		{
			ppre = pcur;
			pcur = pcur->next;
		}
		else
		{
			ppre = pcur->next;
			free(pcur);
			printf("succese\n");
			return 0;
		}
	}
	printf("not found\n");
	return -1;
}