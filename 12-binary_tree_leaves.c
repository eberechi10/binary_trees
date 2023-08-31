#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 * @tree: Pointer to the root node of the tree to count the leaves.
 *
 * Return: The number of leaves in the binary tree, or 0 if tree is NULL
 *
 * Description: This function counts the number of leaf nodes in a binary tree.
 * A leaf node is a node with no children. It recursively counts the leaves in
 * the left and right subtrees. If the tree is NULL, the function returns 0.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
