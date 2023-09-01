#include "binary_trees.h"

/**
 * bt_is_complete - function to check if binary tree is complete.
 *
 * @tree: the root node of the tree.
 * @index: node index.
 *
 * @size: sie of the tree.
 *
 * Return: if success 1, otherwise 0.
 */
int bt_is_complete(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);
	return (bt_is_complete(tree->left, 2 * index + 1, size) &&
			bt_is_complete(tree->right, 2 * index + 2, size));
}


/**
 * binary_tree_size - func to count size of binary tree.
 *
 * @tree: tree node.
 *
 * Return: if success the tree, otherwise 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
			binary_tree_size(tree->right) + 1);
}


/**
 * binary_tree_is_complete - func to check binary tree is complete.
 *
 * @tree: root node of the tree.
 *
 * Return: 1 success, otherwise 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = binary_tree_size(tree);

	return (bt_is_complete(tree, 0, size));
}
