#include "binary_trees.h"

/**
 * bst_search - Search for value in a Binary Search Tree
 * @tree: pointer to root node of the BST to search
 * @value: value to search for in the tree
 *
 * Return: pointer to the node containing the value, or NULL if not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
	{
		return (NULL);
	}

	while (tree != NULL)
	{
		if (value == tree->n)
		{
			return ((bst_t *)tree);
		}
		else if (value < tree->n)
		{
			tree = tree->left;
		}
		else
		{
			tree = tree->right;
		}
	}
	return (NULL);
}

