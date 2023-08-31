#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs left rotation on a binary tree.
 * @root: pointer to root node of the tree to rotate.
 *
 * Return: pointer to new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *root)
{
	binary_tree_t *new_root;

	if (root == NULL || root->right == NULL)
		return (NULL);

	new_root = root->right;
	root->right = new_root->left;

	if (new_root->left != NULL)
	new_root->left->parent = root;

	new_root->parent = root->parent;
	root->parent = new_root;
	new_root->left = root;

	return (new_root);
}
