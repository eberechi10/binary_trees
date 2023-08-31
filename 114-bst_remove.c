#include "binary_trees.h"

/**
 * bst_find_min - Find the node with the minimum value in a BST
 * @node: Pointer to the root node of the subtree
 *
 * Return: Pointer to the node with the minimum value in the subtree
 */
bst_t *bst_find_min(bst_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * bst_remove - remove node from a Binary Search Tree
 * @root: pointer to root node of the tree
 * @value: value to remove from the tree
 *
 * Return: pointer to the new root node after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
	{
		return (NULL);
	}

	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
	}
	else if (value > root->n)
	{
		root->right = bst_remove(root->right, value);
	}
	else
	{
		if (root->left == NULL)
		{
			bst_t *temp = root->right;

			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;

			free(root);
			return (temp);
		}

	bst_t *successor = bst_find_min(root->right);

	root->n = successor->n;
	root->right = bst_remove(root->right, successor->n);
	}

	return (root);
}
