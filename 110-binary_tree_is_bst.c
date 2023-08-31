#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is valid Binary Search Tree.
 * @tree: pointer to root node of the tree to check.
 *
 * Return: Success 1 if tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_bst_helper - help function to recursively check if a tree is a valid BST.
 * @subtree: pointer to the root node of the subtree to check.
 * @lower_bound: Minimum allowed value for the nodes.
 * @upper_bound: Maximum allowed value for the nodes.
 *
 * Return: Success 1 if subtree is a valid BST, 0 otherwise.
 */
int is_bst_helper(const binary_tree_t *subtree, int lower_bound,
		int upper_bound)
{
	if (subtree == NULL)
		return (1);

	if (subtree->n <= lower_bound || subtree->n >= upper_bound)
		return (0);

	return (is_bst_helper(subtree->left, lower_bound, subtree->n) &&
			is_bst_helper(subtree->right, subtree->n, upper_bound));
}
