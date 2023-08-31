#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 * @tree: Pointer to root node of the tree to count the nodes
 *
 * Return: The number of nodes with at least 1 child in the binary tree,
 *         or 0 if tree is NULL
 *
 * Description: This function counts the number of nodes in a binary tree that
 * have at least 1 child. It recursively counts the nodes with children in the
 * left and right subtrees. If the tree is NULL, the function returns 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));

	return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
