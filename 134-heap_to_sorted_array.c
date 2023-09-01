#include "binary_trees.h"

/**
 * tree_s - counts size of a the binary tree.
 *
 * @tree: root node of the tree.
 *
 * Return: if success height, otherwise 0.
 */
size_t tree_s(const binary_tree_t *tree)
{
	size_t height_ri = 0;
	size_t height_le = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_le = 1 + tree_s(tree->left);
	if (tree->right)
		height_ri = 1 + tree_s(tree->right);

	return (height_le + height_ri);
}


/**
 * heap_to_sorted_array - func to convert Binary max sorted array int.
 *
 * @heap: root node of the heap.
 * @size: size of the array.
 *
 * Return: if success array, otherwise NULL.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int idx, *arr = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_s(heap) + 1;

	arr = malloc(sizeof(int) * (*size));
	if (!arr)
		return (NULL);

	for (idx = 0; heap; idx++)
		arr[idx] = heap_extract(&heap);
	return (arr);
}
