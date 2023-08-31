#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node.
 * @node: A pointer to the node to find the sibling.
 *
 * Return: A pointer to the sibling node, or NULL if node is NULL,
 * the parent is NULL, or if node has no sibling.
 *
 * Description: This function returns the sibling node of the given node.
 * If the node is NULL, the parent is NULL, or the node has no sibling,
 * the function returns NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL ||
	(node->parent->left == NULL && node->parent->right == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}
