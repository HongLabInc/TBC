#pragma once

#include <stdbool.h>

#define TSIZE 45

struct film
{
	char title[TSIZE];
	int rating;
};

/* General type definitions */

typedef struct film Item;

typedef struct node
{
	Item item;
	struct node* next;
} Node;

typedef Node* List;

void InitializeList(List* plist); // double pointer
bool ListIsEmpty(const List* plist);
bool ListIsFull(const List* plist);
unsigned int ListItemCount(const List* plist);
bool AddItem(Item item, List* plist);
void Traverse(const List* plist, void (*pfun)(Item item));
void EmptyTheList(List* plist);

