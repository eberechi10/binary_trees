#include "binary_trees.h"

/**
 * array_to_avl - build an AVL tree from an array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	avl_t *root = NULL;

	for (size_t idx = 0; idx < size; idx++)
	{
		avl_insert(&root, array[idx]);
	}

	return (root);
}
