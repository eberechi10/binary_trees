#include "binary_trees.h"

/**
 * array_to_bst - func to build binary search tree (BST).
 *
 * @array: the array to build from.
 * @size: size of the array.
 *
 * Return: if success the created BST, otherwise NULL.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t idx;

	if (array == NULL || size == 0)
		return (NULL);

	for (idx = 0; idx < size; idx++)
		bst_insert(&root, array[idx]);

	return (root);
}
