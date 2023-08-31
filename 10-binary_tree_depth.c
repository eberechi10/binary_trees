
#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 *
 * Return: Success on depth of the node, or 0 if tree is NULL
 *
 * Description: This function calculates the depth of a specific node in a
 * binary tree. The depth of a node is length of the path from the root node
 * to the given node. The depth of the root node is 0. If the node is NULL,the
 * function returns 0.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
		depth++;
	tree = tree->parent;

	return (depth);
}
