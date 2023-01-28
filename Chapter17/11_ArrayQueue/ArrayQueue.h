#pragma once

#include <stdbool.h>

#define TSIZE 45
#define MAXSIZE 4 //Note: capacity is MAXSIZE - 1

struct element
{
	char name[TSIZE];
} element;

typedef struct element Item;

typedef struct queue
{
	int front;
	int rear;
	int n_items;
	Item items[MAXSIZE];
} Queue;

void InitializeQueue(Queue* pq);
bool QueueIsFull(const Queue* pq);
bool QueueIsEmpty(const Queue* pq);
int  QueueItemCount(const Queue* pq);
bool EnQueue(Item item, Queue* pq);
bool DeQueue(Item* pitem, Queue* pq);
void EmptyTheQueue(Queue* pq);
void TraverseQueue(Queue* pq, void (*func)(Item item));//Note: careful

