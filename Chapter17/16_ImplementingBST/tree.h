#pragma once

#include <stdbool.h>

#define TMAX 20

typedef struct 
{
	char character[TMAX];
	char name[TMAX];
} Item;

#define MAXITEMS 20

typedef struct node
{
	Item item;
	struct node* left;	// Root of left branch
	struct node* right;	// Root of right branch
} Node;

typedef struct tree
{
	Node* root;			
	int size;			// Number of items
} Tree;

void InitializeTree(Tree* ptree, int(comp_func)(const Item item1, const Item item2));
bool TreeIsEmpty(const Tree* ptree);
bool TreeIsFull(const Tree* ptree);
int  TreeItemCount(const Tree* ptree);
bool AddItem(const Item* pi, Tree* ptree);
bool InTree(const Item* pi, const Tree* ptree);
bool DeleteItem(const Item* pi, Tree* ptree);
void Traverse(const Tree* ptree, void (*pfun)(Item item));
void DeleteAll(Tree* ptree);
Item* TreeSearch(Tree* tree, const Item key);

/*

Hint:
1.
static void InOrder(const Node* root, void (*pfun)(Item item))
{
	if (root == NULL)
		return;

	InOrder(root->left, pfun);
	(*pfun)(root->item);
	InOrder(root->right, pfun);
}

void Traverse(const Tree* ptree, void (*pfun)(Item item))
{
	if (ptree != NULL)
		InOrder(ptree->root, pfun);
}

2. 
for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
	continue;

3.
typedef struct pair 
{
	Node* parent;
	Node* child;
} Pair;

static Pair SeekItem(const Item* pi, const Tree* ptree);

*/