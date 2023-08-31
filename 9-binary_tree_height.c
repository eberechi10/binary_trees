#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to root node of the tree to measure
 *
 * Return: Success gives height of the tree, or 0 if tree is NULL
 *
 * Description: This function calculates the height of a binary tree.The height
 * of a binary tree is the length of the longest path from the root node to a
 * leaf node. The height of an empty tree (tree == NULL) is considered 0.
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
