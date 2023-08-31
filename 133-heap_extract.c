#include "binary_trees.h"

/**
 * heapify_h - handles max heap property value
 *
 * @root: root node of the heap
 */
void heapify_h(heap_t *root)
{
	heap_t *lag;
	int value;

	while (1)
	{
		if (!root->left)
			break;

		if (!root->right || root->left->n > root->right->n)
			lag = root->left;
		else
			lag = root->right;
		if (root->n > lag->n)
			break;

		value = root->n;
		root->n = lag->n;
		lag->n = value;

		root = lag;
	}
}


/**
 * heap_extract - func to extract root node of Max Binary Heap.
 *
 * @root: the root node of the heap
 *
 * Return: success the value, otherwise 0.
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *node;

	if (!root || !*root)
		return (0);

	value = (*root)->n;
	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (value);
	}
	node = *root;
	while (node->left || node->right)
	{
		if (!node->right || (node->left && node->left->n >= node->right->n))
		{
			node->n = node->left->n;
			node = node->left;
		}
		else
		{
			node->n = node->right->n;
			node = node->right;
		}
	}

	if (node->parent->left == node)
		node->parent->left = NULL;
	else
		node->parent->right = NULL;

	free(node);
	heapify_h(*root);
	return (value);
}
