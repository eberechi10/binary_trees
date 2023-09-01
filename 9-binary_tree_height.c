#include "binary_trees.h"


/**
 * count_height - counts the height of the binary tree.
 *
 * @tree: tree node
 * @height: height of the tree.
 *
 * @mx: the max height
 */
void count_height(const binary_tree_t *tree, size_t height, size_t *mx)
{
	if (tree)
	{
		if (tree->left == NULL && tree->right == NULL)
		{
			if (height > *mx)
			{
				*mx = height;
			}
		}
		else
		{
			count_height(tree->left, height + 1, mx);

			count_height(tree->right, height + 1, mx);
		}
	}
}


/**
 * binary_tree_height - func to measure the height of binary tree.
 *
 * @tree: the root node of the tree.
 *
 * Return: if success height, otherwise 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t mx_height = 0;

	count_height(tree, 0, &mx_height);
	return (mx_height);
}
