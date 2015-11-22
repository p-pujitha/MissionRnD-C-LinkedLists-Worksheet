/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

void sll_012_sort(struct node *head){

	int flag = 1;
	struct node *ptr1, *ptr2;
	ptr1 = head;
	ptr2 = head;
	while (ptr2->next != NULL)
	{
		int temp = ptr2->data;
		ptr2 = ptr2->next;
		if (temp <= ptr2->data)
		{
			flag = 1;
		}
		else
		{
			flag = 0;
			break;
		}

	}
	if (flag == 0)
	{
		while (ptr2->next != NULL)
		{
			ptr2 = ptr2->next;
			if (ptr2->data == 0)
			{
				int temp = ptr1->data;
				ptr1->data = ptr2->data;
				ptr2->data = temp;
				ptr1 = ptr1->next;
			}


		}
		ptr2 = ptr1;
		while (ptr2->next != NULL)
		{
			ptr2 = ptr2->next;
			if (ptr2->data == 1)
			{
				int temp = ptr1->data;
				ptr1->data = ptr2->data;
				ptr2->data = temp;
				ptr1 = ptr1->next;
			}
		}
	}
}