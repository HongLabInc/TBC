#include "LinkedQueue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

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

	/* Array implementation */
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

	/* Array implementation */
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

	/* Array implementation */
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

	/* Array implementation */
	//for (int i = pq->front; i != pq->rear; i = (i + 1) % MAXSIZE)
	//	(*func)(pq->items[(i + 1) % MAXSIZE]);
	//Note: be careful with conditions
}