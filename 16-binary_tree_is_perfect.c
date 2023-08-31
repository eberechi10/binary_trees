#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree, or 0 if the tree is NULL.
 *
 * Description: This function recursively calculates the height of the
 * binary tree by finding the maximum height of its left and right subtrees.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: Success 1 if the tree is perfect, 0 otherwise.
 *
 * Description: This function checks if the given binary tree is perfect,
 * meaning that all its levels are completely filled. If the tree is NULL,
 * the function returns 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, nodes;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	nodes = (1 << height) - 1;

	return (nodes == binary_tree_size(tree));
}
