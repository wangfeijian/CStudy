#define _CRT_SECURE_NO_WARNINGS
#include "../header/linked_list.h"

PNODE create_linked_list(int length)
{
	PNODE pHead = (PNODE)malloc(sizeof(struct Node));
	pHead->pNext = NULL;

	PNODE pTemp = pHead;

	for (int i = 0; i < length; i++)
	{
		int temp;
		printf("请输入第%d个数：", i + 1);
		scanf("%d", &temp);

		PNODE pTail = (PNODE)malloc(sizeof(struct Node));
		pTemp->pNext = pTail;
		pTail->value = temp;
		pTail->pNext = NULL;
		pTemp = pTail;
	}

	return pHead;
}

void show_linked_list_value(PNODE pHead)
{
	while (NULL != pHead->pNext)
	{
		pHead = pHead->pNext;
		printf("%d\n", pHead->value);
	}
}