#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to root node of the tree to measure the size
 *
 * Return: The size of the binary tree, or 0 if tree is NULL
 *
 * Description: This function calculates the number of nodes in a binary tree.
 * It recursively counts the nodes in left and right subtrees and adds 1 for
 * the current node. If the tree is NULL, the function returns 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
