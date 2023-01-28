#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include "LinkedQueue.h"

Item get_item(const char * name)
{
	Item new_item;
	strcpy(new_item.name, name);	
	return new_item;
}

void print_item(Item item)
{
	printf("%s ", item.name);
}

void print_queue(Queue* pq)
{
	printf("Front: %s at %p, Rear: %s at %p, Size %d\n", 
		pq->front == NULL ? "NULL" : pq->front->item.name, pq->front, 
		pq->rear == NULL ? "NULL" : pq->rear->item.name, pq->rear, pq->n_items);
	
	printf("Queue : ");
	if (QueueIsEmpty(pq))
		printf("Empty");
	else
		TraverseQueue(pq, &print_item);
	printf("\n\n");
}

int main()
{
	Queue queue;
	Item temp;

	InitializeQueue(&queue);

	EnQueue(get_item("Jack"), &queue);
	print_queue(&queue);

	EnQueue(get_item("Henry"), &queue);
	print_queue(&queue);

	EnQueue(get_item("Stan"), &queue);
	print_queue(&queue);

	EnQueue(get_item("Butters"), &queue);
	print_queue(&queue);

	if(DeQueue(&temp, &queue))
		printf("Item from queue: %s\n", temp.name);
	print_queue(&queue);

	if (DeQueue(&temp, &queue))
		printf("Item from queue: %s\n", temp.name);
	print_queue(&queue);

	if (DeQueue(&temp, &queue))
		printf("Item from queue: %s\n", temp.name);
	print_queue(&queue);

	if (DeQueue(&temp, &queue))
		printf("Item from queue: %s\n", temp.name);
	print_queue(&queue);

	printf("------ Circulation Test ------------\n");
	InitializeQueue(&queue);

	for (int i = 0; i < 10; ++i)
	{
		EnQueue(get_item("Hello"), &queue);
		print_queue(&queue);

		if (DeQueue(&temp, &queue))
			printf("Item from queue: %s\n", temp.name);
		print_queue(&queue);
	}

	return 0;
}







/* Single file implementation for online compiler

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>



#include <stdio.h>
#include <string.h>


#define TSIZE 45
#define MAXITEMS 3 // Optional

struct element
{
	char name[TSIZE];
} element;

typedef struct element Item;

typedef struct node
{
	Item item;
	struct node* next;
} Node;

typedef struct queue
{
	Node* front;
	Node* rear;
	//int front;
	//int rear;
	int n_items; // number of items
	//Item items[MAXSIZE];
} Queue;

void InitializeQueue(Queue* pq);
bool QueueIsFull(const Queue* pq);
bool QueueIsEmpty(const Queue* pq);
int  QueueItemCount(const Queue* pq);
bool EnQueue(Item item, Queue* pq);
bool DeQueue(Item* pitem, Queue* pq);
void EmptyTheQueue(Queue* pq);
void TraverseQueue(Queue* pq, void (*func)(Item item));

static void CopyToNode(Item item, Node* pn)
{
	pn->item = item;
}

static void CopyToItem(Node* pn, Item* pi)
{
	*pi = pn->item;
}

void InitializeQueue(Queue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;
	pq->n_items = 0;
}

bool QueueIsFull(const Queue* pq)
{
	return pq->n_items == MAXITEMS;
}

bool QueueIsEmpty(const Queue* pq)
{
	//return pq->front == pq->rear;
	return pq->n_items == 0;
}

int  QueueItemCount(const Queue* pq)
{
	return pq->n_items;
}

bool EnQueue(Item item, Queue* pq)
{
	if (QueueIsFull(pq))
	{
		printf("Queue is full. Cannot enqueue.\n");
		return false;
	}

	// make a new node
	Node* pnew;
	pnew = (Node*)malloc(sizeof(Node));
	if (pnew == NULL)
	{
		printf("Malloc() failed.\n");
		return false;
	}
	CopyToNode(item, pnew);
	pnew->next = NULL;

	// add new node at the end
	if (QueueIsEmpty(pq))
		pq->front = pnew;
	else
		pq->rear->next = pnew;
	pq->rear = pnew;
	pq->n_items++;

	// Array implementation 
	//pq->rear = (pq->rear + 1) % MAXSIZE; // Use % for circular queue
	//pq->items[pq->rear] = item;
	//pq->size++;

return true;
}

bool DeQueue(Item* pitem, Queue* pq)
{
	if (QueueIsEmpty(pq))
	{
		printf("Queue is empty. Cannot dequeue.\n");
		return false;
	}

	Node* pn;
	CopyToItem(pq->front, pitem);
	pn = pq->front;
	pq->front = pq->front->next;//next may be NULL
	free(pn);
	pq->n_items--;
	if (pq->n_items == 0)
		pq->rear = NULL;

	// Array implementation //
	//pq->front = (pq->front + 1) % MAXSIZE;	// Use % circular queue
	//*pitem = pq->items[pq->front];
	//pq->size--;

	return true;
}

void EmptyTheQueue(Queue* pq)
{
	Item temp;
	while (!QueueIsEmpty(pq))
		DeQueue(&temp, pq);

	// Array implementation //
	//InitializeQueue(pq);
}

void TraverseQueue(Queue* pq, void (*func)(Item item))
{
	Node* temp = pq->front;
	while (temp != NULL)
	{
		(*func)(temp->item);
		temp = temp->next;
	}

	// Array implementation //
	//for (int i = pq->front; i != pq->rear; i = (i + 1) % MAXSIZE)
	//	(*func)(pq->items[(i + 1) % MAXSIZE]);
	//Note: be careful with conditions
}

Item get_item(const char* name)
{
	Item new_item;
	strcpy(new_item.name, name);
	return new_item;
}

void print_item(Item item)
{
	printf("%s ", item.name);
}

void print_queue(Queue* pq)
{
	printf("Front: %s at %p, Rear: %s at %p, Size %d\n",
		pq->front == NULL ? "NULL" : pq->front->item.name, pq->front,
		pq->rear == NULL ? "NULL" : pq->rear->item.name, pq->rear, pq->n_items);

	printf("Queue : ");
	if (QueueIsEmpty(pq))
		printf("Empty");
	else
		TraverseQueue(pq, &print_item);
	printf("\n\n");
}

int main()
{
	Queue queue;
	Item temp;

	InitializeQueue(&queue);

	EnQueue(get_item("Jack"), &queue);
	print_queue(&queue);

	EnQueue(get_item("Henry"), &queue);
	print_queue(&queue);

	EnQueue(get_item("Stan"), &queue);
	print_queue(&queue);

	EnQueue(get_item("Butters"), &queue);
	print_queue(&queue);

	if (DeQueue(&temp, &queue))
		printf("Item from queue: %s\n", temp.name);
	print_queue(&queue);

	if (DeQueue(&temp, &queue))
		printf("Item from queue: %s\n", temp.name);
	print_queue(&queue);

	if (DeQueue(&temp, &queue))
		printf("Item from queue: %s\n", temp.name);
	print_queue(&queue);

	if (DeQueue(&temp, &queue))
		printf("Item from queue: %s\n", temp.name);
	print_queue(&queue);

	printf("------ Circulation Test ------------\n");
	InitializeQueue(&queue);

	for (int i = 0; i < 10; ++i)
	{
		EnQueue(get_item("Hello"), &queue);
		print_queue(&queue);

		if (DeQueue(&temp, &queue))
			printf("Item from queue: %s\n", temp.name);
		print_queue(&queue);
	}

	return 0;
}



*/