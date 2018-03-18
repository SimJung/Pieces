#include <stdio.h>
#include <stdlib.h>

typedef struct __LinkedList
{
	int data;
	__LinkedList *n_next;
} ll;

void ll_init(ll *list)
{
	list->data = 0;
	list->n_next = NULL;
}

void ll_push(ll *list, int temp)
{
	while(list->n_next != NULL)
		list = list->n_next;
		
	list->n_next = (ll*)malloc(sizeof(ll));
	list->n_next->data = temp;
	list->n_next->n_next = NULL;
}

void ll_

void ll_print(ll *list)
{
	while(list->n_next != NULL)
	{
		printf("data : %d\n", list->data);
		list = list->n_next;
	}
	printf("data : %d\n", list->data);
}

int main(void)
{
	ll *n_head = NULL, *n_tail = NULL, *n_temp;
	
	n_temp = (ll*)malloc(sizeof(ll));
	ll_init(n_temp);
	n_head = n_temp;
	
	n_temp->data = 6;
	
	ll_push(n_temp, 10);
	ll_push(n_temp, 12);
	ll_push(n_head, 15);
	
	ll_print(n_head);
	
	return 0;
}
