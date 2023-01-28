#include "ArrayQueue.h"
#include <assert.h>
#include <stdio.h>

void TraverseQueue(Queue* pq, void (*func)(Item item))
{
	for (int i = pq->front; i != pq->rear; i = (i + 1) % MAXSIZE)
		(*func)(pq->items[(i + 1) % MAXSIZE]);
	//Note: be careful with conditions
}

















void InitializeQueue(Queue* pq) 
{
	pq->front = 0;
	pq->rear = 0;
	pq->n_items = 0;
}

bool QueueIsFull(const Queue* pq)
{
	//Note: do not use MAXSIZE directly.
	return (pq->rear + 1) % MAXSIZE == pq->front;
}

bool QueueIsEmpty(const Queue* pq)
{
	return pq->front == pq->rear;
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

	pq->rear = (pq->rear + 1) % MAXSIZE; // Use % for circular queue
	pq->items[pq->rear] = item;
	pq->n_items++;

	return true;
}

bool DeQueue(Item* pitem, Queue* pq)
{
	if (QueueIsEmpty(pq))
	{
		printf("Queue is empty. Cannot dequeue.\n");
		return false;
	}

	pq->front = (pq->front + 1) % MAXSIZE;	// Use % circular queue
	*pitem = pq->items[pq->front];
	pq->n_items--;

	return true;
}

void EmptyTheQueue(Queue* pq)
{
	InitializeQueue(pq);
}

