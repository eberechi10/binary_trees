#include "binary_trees.h"

/**
 * binary_tree_postorder - Goes through binary tree using post-order traversal
 * @tree: Pointer to  root node of tree to traverse
 * @func: Pointer to function to call for each node
 *
 * Description: This function traverses a binary tree in post-order and applies
 * the given function to each visited node. The value in the node is passed as
 * a parameter to the function.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
