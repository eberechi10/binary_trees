#include "binary_trees.h"


/**
 * count_nodes - func to count the nodes on the binary tree.
 *
 * @tree: tree node
 * @size: size of the node
 */
void count_nodes(const binary_tree_t *tree, size_t *size)
{
	if (tree)
	{
		(*size)++;
		count_nodes(tree->left, size);

		count_nodes(tree->right, size);
	}
}

/**
 * binary_tree_size - func to measure nodes of the binary.
 *				tree.
 * @tree: the root node of the binary tree
 *
 * Return: if success the nodesotherwise 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size_n = 0;

	if (tree == NULL)
		return (size_n);

	count_nodes(tree, &size_n);

	return (size_n);
}
