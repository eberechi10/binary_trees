#include "binary_trees.h"


/**
 * btc_helper - func to check binary tree is complete.
 *
 * @tree: root node of the tree
 * @index: the index node.
 *
 * @size: the size of the tree.
 *
 * Return: if 1 success, otherwise 0 if failure or Null.
 */
int btc_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (btc_helper(tree->left, 2 * index + 1, size) &&
		btc_helper(tree->right, 2 * index + 2, size));
}


/**
 * bt_helper - func to check binary tree is a valid max binary heap.
 *
 * @tree: root node of the tree.
 *
 * Return: 1 if success or Null, otherwise 0.
 */
int bt_helper(const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	if (!binary_tree_is_complete(tree))
		return (0);

	if (tree->left)
		if (tree->left->n > tree->n)
			return (0);
	if (tree->right)
		if (tree->right->n > tree->n)
			return (0);

	return (bt_helper(tree->left) &&
		bt_helper(tree->right));
}


/**
 * binary_tree_is_heap - checks binary tree is a max binary heap.
 *
 * @tree: root node of the tree
 *
 * Return: if 1 success, otherwise 0 if failure or Null.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bt_helper(tree));
}


/**
 * binary_tree_is_complete - func to check binary tree is complete
 *
 * @tree: root node of the tree.
 *
 * Return: if 1 success, otherwise 0 if failure or Null.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = binary_tree_size(tree);

	return (btc_helper(tree, 0, size));
}


/**
 * binary_tree_size -func to count size of binary tree.
 *
 * @tree: the size of the tree.
 *
 * Return: if success size tree, otherwise 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
