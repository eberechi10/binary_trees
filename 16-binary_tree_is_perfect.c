#include "binary_trees.h"


/**
 * binary_tree_height - func to measure the height of a binary tree.
 *
 * @tree: root node of the tree to measure the height.
 *
 * Return: if success height of the tree, otherwise 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left = 0, right = 0;

		if (tree->left)
			left = 1 + binary_tree_height(tree->left);

		if (tree->right)
			right = 1 + binary_tree_height(tree->right);

		if (left > right)
			return (left);
		else
			return (right);
	}
	else
		return (0);
}


/**
 * binary_tree_size - func to measure size binary tree.
 *
 * @tree: root node of the tree the size.
 *
 * Return: if success nodes of binary tree. otherwise 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t n_left = 0, n_right;

	if (tree == NULL)
		return (0);

	n_right = binary_tree_size(tree->right);

	return (1 + n_left + n_right);
}


/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 *
 * @tree: node of the tree.
 *
 * Return: if success 1, otherwise 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t hi_node = 0, perfect_size = 0;

	if (tree == NULL)
		return (0);

	hi_node = binary_tree_height(tree);

	perfect_size = (1 << (hi_node + 1)) - 1;

	if (perfect_size == binary_tree_size(tree))
		return (1);
	else
		return (0);
}
