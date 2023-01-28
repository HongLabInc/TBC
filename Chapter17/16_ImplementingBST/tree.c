#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

typedef struct pair 
{
	Node* parent;
	Node* child;
} Pair;

/* Prototypes for local functions */

static Node* MakeNode(const Item* pi);
static void AddNode(Node* new_node, Node* root);
static void InOrder(const Node* root, void (*pfun)(Item item));
static Pair SeekItem(const Item* pi, const Tree* ptree);
static void DeleteNode(Node** ptr);
static void DeleteAllNodes(Node* ptr);
static Item* Search(Node* root, const Item to_search);

static int(*compare_func)(const Item item1, const Item item2) = NULL;

/* function definitions */

void InitializeTree(Tree* ptree, int(comp_func)(const Item item1, const Item item2))
{
	ptree->root = NULL;
	ptree->size = 0;
	compare_func = comp_func;
}

static void AddNode(Node* new_node, Node* root)
{
	int comp = compare_func(new_node->item, root->item);

	if (comp == 0)
	{
		printf("Cannot add a duplicated item.\n");
		free(new_node);
		return;
	}
	else if (comp < 0) // left branch
	{
		if (root->left == NULL) // left branch is empty
			root->left = new_node;
		else
			AddNode(new_node, root->left);
	}
	else // compare > 0
	{
		if (root->right == NULL)
			root->right = new_node;
		else
			AddNode(new_node, root->right);
	}
}

bool AddItem(const Item* pi, Tree* ptree)
{
	if (TreeIsFull(ptree))
	{
		printf("Cannot add more items.\n");
		return false;
	}

	Node * new_node = MakeNode(pi);

	ptree->size++;

	if (ptree->root == NULL)
		ptree->root = new_node;
	else
		AddNode(new_node, ptree->root);

	return true;
}

bool TreeIsEmpty(const Tree* ptree)
{
	if (ptree->root == NULL)
		return true;
	else
		return false;
}

bool TreeIsFull(const Tree* ptree)
{
	if (ptree->size == MAXITEMS)
		return true;
	else
		return false;
}

int TreeItemCount(const Tree* ptree)
{
	return ptree->size;
}

bool InTree(const Item* pi, const Tree* ptree)
{
	return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item* pi, Tree* ptree)
{
	Pair look;

	look = SeekItem(pi, ptree);
	if (look.child == NULL)
		return false;

	if (look.parent == NULL)
		DeleteNode(&ptree->root);
	else if (look.parent->left == look.child)
		DeleteNode(&look.parent->left);
	else
		DeleteNode(&look.parent->right);
	ptree->size--;

	return true;
}

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

void DeleteAll(Tree* ptree)
{
	if (ptree == NULL)
		return;

	DeleteAllNodes(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}

static void DeleteAllNodes(Node* root)
{
	if (root == NULL)
		return;

	Node* pright = root->right;
	DeleteAllNodes(root->left);
	free(root);
	DeleteAllNodes(pright);
}

static Node* MakeNode(const Item* pi)
{
	Node* new_node;

	new_node = (Node*)malloc(sizeof(Node));

	if (new_node != NULL)
	{
		new_node->item = *pi;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	else
	{
		printf("Malloc() failed.\n");
		exit(1);
	}

	return new_node;
}

static Item* Search(Node* root, const Item key)
{
	if (root == NULL)
		return NULL;

	int comp = compare_func(key, root->item);

	// This is an example of preorder traversal
	if (comp == 0)
		return &root->item;
	else if (comp < 0)
		return Search(root->left, key);
	else // comp > 0
		return Search(root->right, key);
}

Item* TreeSearch(Tree* tree, const Item key)
{
	return Search(tree->root, key);
}

static Pair SeekItem(const Item* pi, const Tree* ptree)
{
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;

	if (look.child == NULL)
		return look;

	while (look.child != NULL)
	{
		int comp = compare_func(*pi, look.child->item);

		if (comp < 0)
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (comp > 0)
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else // comp == 0
			break;
	}

	return look;
}

static void DeleteNode(Node** ptr)
/* ptr is address of parent member pointing to target node */
{
	Node* temp;

	if ((*ptr)->left == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	}
	else if ((*ptr)->right == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
	else		/* deleted node has two children */
	{
		/* find where to reattach right subtree */
		for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
			continue;
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
}