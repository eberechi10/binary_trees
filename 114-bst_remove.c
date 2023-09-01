#include "binary_trees.h"


/**
 * bst_find_min - func to find node with minimum value in a BST.
 * @root: root node of the BST.
 *
 * Return: If success the node with the minimum value.
 */
bst_t *bst_find_min(bst_t *root)
{
	while (root && root->left)

		root = root->left;

	return (root);
}


/**
 * bst_remove - func to remove node from BST
 *
 * @root: the root node of BST.
 * @value: node value.
 *
 * Return: the new root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *m_right, *elm;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);

	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			elm = root->right;
			free(root);
			return (elm);
		}
		else if (root->right == NULL)
		{
			elm = root->left;

			free(root);
			return (elm);
		}
		m_right = bst_find_min(root->right);

		root->n = m_right->n;
		root->right = bst_remove(root->right, m_right->n);
	}

	return (root);
}
