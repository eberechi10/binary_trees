#include "binary_trees.h"

/**
 * binary_tree_preorder - moves through a binary tree
 * @tree: Pointer to root node of the tree to traverse
 * @func: Pointer to function to call for each node
 *
 * Description: This function traverses a binary tree in pre-order and applies
 * the given function to each visited node. The value in the node is passed as
 * a parameter to the function.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
