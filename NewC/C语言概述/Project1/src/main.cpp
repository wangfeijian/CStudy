#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "header/equation_demo.h"
#include "header/function_demo.h"
#include "header/cpoint_unit1.h"
#include "header/cpoint_unit4.h"
#include "header/linked_list.h"

int main(void)
{
	PNODE p = create_linked_list(5);
	show_linked_list_value(p);
	return 0;
}