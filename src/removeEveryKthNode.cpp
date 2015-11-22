/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	struct node *ptr;
	int length = 0;
	ptr = head;
	int count = 1;
	if (ptr == NULL || K < 0 || K == 0)
		return NULL;
	if (K == 1)
	{
		ptr = head;
		ptr->next = NULL;
		return NULL;
	}
	struct node *cur = head;
	struct node *pre;
	while (cur->next!=NULL)
	{
		pre = cur;
		cur = cur->next;
		count++;
		if (count%K==0)
		{
			pre->next = cur->next;

		}
	}
	if (K%2 == 0)
		pre->next == NULL;

	return head;
}