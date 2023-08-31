#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: Pointer to the node to insert the right-child in
 * @value: Value to store in the new node.
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 *
 * Description: This function inserts a new node with the given value as the
 * right-child of the parent node. If successful, the function returns a
 * pointer to the newly created node; otherwise, it returns NULL.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->parent = parent;
	new->n = value;
	new->right = parent->right;
	new->left = NULL;

	if (parent->right != NULL)
	parent->right->parent = new;

	parent->right = new;

	return (new);
}

