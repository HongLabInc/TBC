#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "tree.h"

#define SPACING 30

int compare(const Item first, const Item second)
{
	return strcmp(first.character, second.character);
}

void print_item(Item item)
{
	printf("%s (%s)\n", item.character, item.name);
}

// https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
void print2DUtil(Node* root, int space)
{
	// Increase distance between levels  
	space += SPACING;

	if (root == NULL)
	{
		for (int i = SPACING; i < space; i++)
			printf(" ");
		printf("NULL");
		return;
	}

	// Process right child first  
	print2DUtil(root->right, space);

	// Print current node after space  
	// count  
	printf("\n");
	for (int i = SPACING; i < space; i++)
		printf(" ");
	print_item(root->item);

	// Process left child  
	print2DUtil(root->left, space);
}

void print_node(Node* root, int level)
{
	if (root == NULL)
		return;

	printf("%s (%s) -> ", root->item.character, root->item.name);
	
	if (root->left == NULL)
		printf("NULL, ");
	else
		printf("%s (%s), ", root->left->item.character, root->left->item.name);

	if (root->right == NULL)
		printf("NULL");
	else
		printf("%s (%s)", root->right->item.character, root->right->item.name);

	printf("\n");

	print_node(root->left, level+1);
	print_node(root->right, level+1);
}

void print_tree(Tree* ptree)
{
	printf("\n-------------------\n");

	Traverse(ptree, print_item);

	printf("\n-------------------\n");

	print2DUtil(ptree->root, 0);

	printf("\n-------------------\n");

	print_node(ptree->root, 0);
}

int main()
{
	/* Assume that there is no duplicated items */

	Item items[] = {
						{"Iron Man", "Tony Stark"},
						{"Thor", "Thor Odinson"},
						{"Ant-Man", "Hank Pym"},
						{"Wasp", "Janet van Dyne"},
						{"Hulk", "Bruce Banner"},
						{"Captain America", "Steve Rogers"},
						{"Scarlet Witch", "Wanda Maximoff"},
						{"Black Widow", "Natasha Romanoff"},
						{"Dr. Strange", "Stephen Strange"},
						{"Daredevil", "Matthew Murdock"},
						{"Punisher", "Frank Castle"},
						{"Batman", "Bruce Wayne"}
	};

	int n = sizeof(items) / sizeof(items[0]);

	Tree tree;
	InitializeTree(&tree, &compare);

	for(int i = 0; i < n; ++i)
		AddItem(&items[i], &tree);

	/* Try to add duplicated item */
	AddItem(&items[2], &tree);
	print_tree(&tree);

	/* Searching Test */
	Item key = { "Punisher", "" };
	Item * result = TreeSearch(&tree, key);
	if (result == NULL)
		printf("\nSearch failed.\n");
	else
		printf("\n%s is the %s\n", result->name, result->character);

	/* Deleting tests */
	{
		Item key = { "Iron Man", "" };
		DeleteItem(&key, &tree);
		print_tree(&tree);
	}

	return 0;
}
