#include "binary_trees.h"

/**
<<<<<<< HEAD
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

=======
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

>>>>>>> 257d95464ec6897e59e326c722f4ea4c5f452cc9
	return (root);
}
