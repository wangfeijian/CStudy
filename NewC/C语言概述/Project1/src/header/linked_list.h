#pragma once
#include <stdlib.h>
#include <stdio.h>

struct Node {
	int value;
	struct Node* pNext;
};

typedef struct Node* PNODE;

PNODE create_linked_list(int);

void show_linked_list_value(PNODE);