#include "SimpleList.h"

#include <stdio.h>
#include <stdlib.h>

static void CopyToNode(Item item, Node* pnode)
{
	pnode->item = item;
}

void InitializeList(List* plist)
{
	plist->head = NULL;
}

bool IsEmpty(const List* plist)
{
	if (plist->head == NULL)
		return true;
	else
		return false;
}

bool IsFull(const List* plist)
{
	// true when malloc fails

	Node* pt;
	bool full;

	pt = (Node*)malloc(sizeof(Node));
	if (pt == NULL)
		full = true;
	else
		full = false;
	free(pt);

	return full;
}

unsigned int CountItems(const List* plist)
{
	unsigned int count = 0;
	Node* pnode = plist->head;

	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;
	}

	return count;
}

bool InsertItemFront(Item item, List* plist)
{
	Node* new_node;
	new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		printf("Malloc failed.\n");
		return false;
	}
	CopyToNode(item, new_node);
	Node* temp = plist->head;
	plist->head = new_node;
	new_node->next = temp;
	return true;
}

bool AppendItem(Item item, Node* prev)
{
	Node* new_node;
	new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		printf("Malloc failed.\n");
		return false;
	}
	CopyToNode(item, new_node);
	Node* temp = prev->next;
	prev->next = new_node;
	new_node->next = temp;

	return true;
}

bool AddItem(Item item, List* plist)
{
	Node* new_node;
	Node* search = plist->head;

	new_node = (Node*)malloc(sizeof(Node));

	if (new_node == NULL)
	{
		printf("Malloc failed.\n");
		return false;
	}

	CopyToNode(item, new_node);

	new_node->next = NULL;

	if (search == NULL)
		plist->head = new_node;
	else
	{
		while (search->next != NULL)
			search = search->next;
		search->next = new_node;
	}

	return true;//TODO: return new_node pointer
}

unsigned int WriteAllItems(const List* plist, FILE* file, void (*write_an_item_func)(FILE* file, Item item))
{
	Node* pnode = plist->head;

	unsigned int count = 0;
	while (pnode != NULL)
	{
		(*write_an_item_func)(file, pnode->item);
		pnode = pnode->next;
		count++;
	}

	return count;
}

unsigned int PrintAllItems(const List* plist, void (*print_an_item_func)(Item item))
{
	Node* pnode = plist->head;
	unsigned int count = 0;
	while (pnode != NULL)
	{
		printf("%d : ", count);
		(*print_an_item_func)(pnode->item);
		pnode = pnode->next;
		count++;
	}

	return count;
}

void Traverse(const List* plist, void (*pfun)(Item item))
{
	Node* pnode = plist->head;

	while (pnode != NULL)
	{
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}

bool Find(const List* plist, Item item_to_find, int* index, Item* item_found, bool (*compare_func)(Item a, Item b))
{
	Node* pnode = plist->head;
	
	*index = 0;
	while (pnode != NULL)
	{
		if ((*compare_func)(pnode->item, item_to_find) == true)
		{
			*item_found = pnode->item;
			return true;
		}

		pnode = pnode->next;
		*index += 1;
	}

	return false;
}

void ClearList(List* plist)
{
	Node* iterator = plist->head;
	Node* temp = NULL;

	while (iterator != NULL)
	{
		temp = iterator->next;
		free(iterator);
		iterator = temp;
	}

	plist->head = NULL;
}

bool FindItemByIndex(const List* plist, const int index, Item** item)
{
	Node* pnode = plist->head;	/* set to start of list */

	int count = 0;

	while (pnode != NULL)
	{
		if (count == index) break;

		pnode = pnode->next;
		count++;
	}

	if (pnode == NULL)
		return false;
	else
	{
		*item = &pnode->item;
		return true;
	}
}

Node* FindNodeByIndex(const List* plist, const int index)
{
	Node* pnode = plist->head;	/* set to start of list */

	int count = 0;

	while (pnode != NULL)
	{
		if (count == index) break;

		pnode = pnode->next;
		count++;
	}

	return pnode;
}

void InsertbyIndex(Item item, List* plist, int index)
{
	Node* prev = FindNodeByIndex(plist, index - 1);

	if (prev == NULL) // when index is 0
		InsertItemFront(item, plist);
	else
		AppendItem(item, prev);
}

void RemoveFirstItem(List* plist)
{
	Node* temp = NULL;
	if (plist->head != NULL)
		temp = plist->head->next;
	free(plist->head);
	plist->head = temp;
}

void RemoveNextItem(Node* prev) 
{
	Node* temp = NULL;
	if (prev->next == NULL)
		temp = NULL;
	else
		temp = prev->next->next;
	free(prev->next);
	prev->next = temp;	
}


void RemoveByIndex(List* plist, int index)
{
	Node* prev = FindNodeByIndex(plist, index - 1);

	if (prev == NULL) // when index is 0
		RemoveFirstItem(plist);
	else
		RemoveNextItem(prev);
}
