#include "binary_trees.h"

/**
 * binary_tree_insert_left -  inserts node as left-child of another node
 *
 * @parent: node to insert the left-child in
 * @value:  node value
 *
 * Return: the created node, otherwise NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_n;

	if (!parent)
		return (NULL);

	new_n = malloc(sizeof(binary_tree_t));
	if (!new_n)
		return (NULL);

	new_n->n = value;
	new_n->parent = parent;
	new_n->right = NULL;
	new_n->left = parent->left;
	parent->left = new;
	if (new_n->left)
		new_n->left->parent = new_n;
	return (new_n);
}
