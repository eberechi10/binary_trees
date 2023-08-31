#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if binary tree is complete.
 * @tree: Pointer to root node of the tree to check.
 *
 * Return: Success 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t idx, nodes_count = 0;
	int flag = 0;
	binary_tree_t **queue;

	if (tree == NULL)
		return (0);

	nodes_count = binary_tree_size(tree);

	queue = malloc(sizeof(binary_tree_t *) * nodes_count);

	if (queue == NULL)
		return (0);

	queue[0] = (binary_tree_t *)tree;

	for (idx = 0; idx < nodes_count; idx++)
	{

		if (queue[idx] != NULL)
		{

			if (flag)
				return (0);

	queue[++idx] = queue[idx]->left;
	queue[++idx] = queue[idx]->right;
		}

		else
			flag = 1;
	}
	free(queue);
	return (1);

}
