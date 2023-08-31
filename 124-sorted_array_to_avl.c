#include "binary_trees.h"


/**
 * sorted_array_to_avl - builds an AVL tree array.
 *
 * @array: the array to be converted.
 * @size: size of the array.
 *
 * Return: if success root node, otherwise Null.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t mi;

	if (!array)
		return (NULL);
	mi = (size - 1) / 2;
	tree = binary_tree_node(NULL, array[mi]);

	sata_helper(&tree, array, -1, mi);
	sata_helper(&tree, array, mi, size);

	return (tree);
}

/**
 * sata_helper -func to help builds AVL tree.
 *
 * @root: root node subtree
 * @array: array to be converted
 *
 * @lo: the lower bound index
 * @hi: the upper bound index
 */
void sata_helper(avl_t **root, int *array, size_t lo, size_t hi)
{
	avl_t *new = NULL;
	size_t mi;

	if (hi - lo > 1)
	{
		mi = (hi - lo) / 2 + lo;
		new = binary_tree_node(*root, array[mi]);

		if (array[mi] > (*root)->n)
			(*root)->right = new;
		else if (array[mi] < (*root)->n)
			(*root)->left = new;

		sata_helper(&new, array, lo, mi);

		sata_helper(&new, array, mi, hi);
	}
}
