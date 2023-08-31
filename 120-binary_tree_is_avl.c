#include "binary_trees.h"

/**
 * binary_tree_height - Calculate the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
	{
		return (0);
	}

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_is_avl - check if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: Success 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance_factor;

	if (tree == NULL)
	{
		return (0);
	}

	balance_factor = binary_tree_height(tree->left) -
		binary_tree_height(tree->right);

	if (balance_factor < -1 || balance_factor > 1)
	{
		return (0);
	}

	return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
