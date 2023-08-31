#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: Double pointer to root node of the BST to insert the value.
 * @value: The value to be stored in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		if (*tree == NULL)
			return (NULL);
		return (*tree);
	}

	if (value == (*tree)->n)
		return (NULL);

	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			if ((*tree)->left == NULL)
				return (NULL);
			return ((*tree)->left);
		}
		return (bst_insert(&((*tree)->left), value));
	}

	if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			if ((*tree)->right == NULL)
				return (NULL);
			return ((*tree)->right);
		}
		return (bst_insert(&((*tree)->right), value));
	}

	return (NULL);
}
