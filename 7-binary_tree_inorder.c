#include "binary_trees.h"

/**
 * binary_tree_inorder - Goes through binary tree using in-order traversal
 * @tree: Pointto the root node of the tree to traverse
 * @func: Point to a function to call for each node
 *
 * Description: This function traverses a binary tree in in-order and applies
 * the given function to each visited node. The value in the node is passed as
 * a parameter to the function.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
