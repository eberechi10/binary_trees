#include "binary_trees.h"


/**
 * binary_tree_height - func to measure height of binary tree..
 *
 * @tree: root node of the tree.
 *
 * Return: if NULL return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left = 0, right = 0;

		if (tree->right)
			right = 1 + binary_tree_height(tree->right);

		if (tree->left)
			left = 1 + binary_tree_height(tree->left);

		if (left > right)
			return (left);

		else
			return (right);
	}
	else
		return (0);
}


/**
 * binary_tree_levelorder - func to go into a binary tree in level-order>
 *
 * @tree: root node of the tree.
 * @func: function to call node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t idx = 1, hi = 1;

	if (tree && func)
	{
		hi = binary_tree_height(tree);
		while (idx <= hi + 1)
		{
			print_at_level(tree, func, idx);
			idx++;
		}
	}

}


/**
 * print_at_level - func to print nodes.
 *
 * @tree: root node of the tree.
 * @func: function to call node.
 *
 * @level: the level to print
 */
void print_at_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree && func)
	{
		if (level == 1)
			func(tree->n);
		else
		{
			print_at_level(tree->left, func, level - 1);

			print_at_level(tree->right, func, level - 1);
		}
	}

}
