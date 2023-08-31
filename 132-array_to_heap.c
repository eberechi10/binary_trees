#include "binary_trees.h"

/**
 * array_to_heap - func to setup Max Binary Heap tree.
 *
 * @array: element of the array.
 * @size: size of the array.
 *
 * Return: if success the binary heap, otherwise Null.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int idx;
	heap_t *root = NULL;

	for (idx = 0; idx < size; idx++)

		heap_insert(&root, array[idx]);
	return (root);
}
