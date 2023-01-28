#pragma once

#include <stdbool.h>

#define SLEN 20

typedef struct item
{
	char petname[20];
	char petkind[20];
} Item;

#define MAXITEMS 10

typedef struct trnode
{
	Item item;
	struct trnode* left;	/* pointer to right branch */
	struct trnode* right;	/* pointer to left branch */
} Trnode;

typedef struct tree
{
	Trnode* root;		/* pointer to root of tree */
	int size;			/* number of items in tree */
} Tree;

/* function prototypes */

/*	operation: initialize a tree to empty 
	preconditions: ptree points to a tree
	postconditions: the tree is initialized to empty */
void InitializeTree(Tree* ptree);

/*	operation: determine if tree is empty 
	preconditions: ptree points to a tree
	postconditions: function returns true if tree is
					empty and returns false otherwise */
bool TreeIsEmpty(const Tree* ptree);

/*  operation: determine if tree is full 
	preconditions: ptree points to a tree
	postconditions: function returns true if tree is
					full and returns false otherwise */
bool TreeIsFull(const Tree* ptree);

/*  operation: determine number of items in tree 
	precondition: ptree points to a tree
	postconditions: function returns number of items in tree */
int TreeItemCount(const Tree* ptree);

/*  operation: add an item to a tree
	preconditions: pi is address of item to be added 
				   ptree points to an initialized tree
	postconditions: if possible, function adds item to
					tree and returns true; otherwise,
					the function returns false */
bool AddItem(const Item* pi, Tree* ptree);

bool InTree(const Item* pi, const Tree* ptree);

bool DeleteItem(const Item* pi, Tree* ptree);

void Traverse(const Tree* ptree, void (*pfun)(Item item));

void DeleteAll(Tree* ptree);
