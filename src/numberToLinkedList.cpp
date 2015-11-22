/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N) {
	struct node *start = NULL, *ptr, *answer;
	if (N == 0)
	{
		answer = (struct node*)malloc(sizeof(struct node));
		answer->num = 0;
		answer->next = NULL;
		return answer;
	}

	if (N < 0)
		N = -(N);

	int a[10], i = 0;
	while (N != 0)
	{
		int rem = N % 10;
		a[i] = rem;
		i++;
		N = N / 10;
	}
	
	int j = i - 1;
	answer = (struct node*)malloc(sizeof(struct node));
	answer->num = a[j];
	answer->next = start;
	start = answer;
	j--;
	while (j >= 0)
	{
		answer = (struct node*)malloc(sizeof(struct node));
		struct node *p = start;
		answer->num = a[j];
		
		while (p->next != NULL)
			p = p->next;
			p->next = answer;
			answer->next = NULL;
		
		j--;
	}
	return start;
}