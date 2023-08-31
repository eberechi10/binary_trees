#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds lowest common ancestor of two nodes.
 * @node_a: Pointer to first node.
 * @node_b: Pointer to second node.
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if no common
 * ancestor was found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *node_a,
				const binary_tree_t *node_b)
{
	size_t depth_a = 0, depth_b = 0;
	const binary_tree_t *temp_a = node_a, *temp_b = node_b;

	if (node_a == NULL || node_b == NULL)
		return (NULL);

	while (temp_a->parent != NULL)
	{
		temp_a = temp_a->parent;
		depth_a++;
	}

	while (temp_b->parent != NULL)
	{
		temp_b = temp_b->parent;
		depth_b++;
	}

	temp_a = node_a;
	temp_b = node_b;

	while (depth_a > depth_b)
	{
		temp_a = temp_a->parent;
		depth_a--;
	}

	while (depth_b > depth_a)
	{
		temp_b = temp_b->parent;
		depth_b--;
	}

	while (temp_a != temp_b)
	{
		temp_a = temp_a->parent;

		temp_b = temp_b->parent;
	}

	return ((binary_tree_t *)temp_a);
}
