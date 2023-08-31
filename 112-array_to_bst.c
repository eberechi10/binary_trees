#include "binary_trees.h"

/**
 * array_to_bst - build Binary Search Tree from an array
 * @array: pointer to first element of the array
 * @size: number of elements in the array
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	bst_t *root = NULL;

	for (size_t idx = 0; idx < size; idx++)
	{
		bst_insert(&root, array[idx]);
	}

	return (root);
}

