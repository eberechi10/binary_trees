#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the binary tree, or 0 if tree is NULL.
 *
 * Description: This function recursively calculates and returns
 * the height of the binary tree starting from the provided root node.
 */
size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The balance factor of the binary tree, or 0 if tree is NULL.
 *
 * Description: This function calculates and returns the balance factor
 * of a binary tree, which is the difference between the height of the
 * left subtree and the height of the right subtree. If the tree is NULL,
 * the function returns 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the binary tree, or 0 if tree is NULL.
 *
 * Description: This function recursively calculates and returns
 * the height of the binary tree starting from the provided root node.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height, r_height;

	if (tree == NULL)
		return (0);

	l_height = binary_tree_height(tree->left);
	r_height = binary_tree_height(tree->right);

	return ((l_height > r_height) ? (l_height + 1) : (r_height + 1));
}
