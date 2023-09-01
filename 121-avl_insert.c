#include "binary_trees.h"

/**
 * r_insert_node - func to insert node value into AVL.
 *
 * @tree: node of the AVL tree.
 * @parent: parent node of AVL.
 *
 * @new: left or right.
 * @nval: value of AVL.
 *
 * Return: if success the new root, otherwise NULL.
 */
avl_t *r_insert_node(avl_t **tree, avl_t *parent, avl_t **new, int nval)
{
	int bvalue;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, nval));
	if ((*tree)->n > nval)
	{
		(*tree)->left = r_insert_node(&(*tree)->left, *tree, new, nval);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < nval)
	{
		(*tree)->right = r_insert_node(&(*tree)->right, *tree, new, nval);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree);
	}
	bvalue = binary_tree_balance(*tree);
	if (bvalue > 1 && (*tree)->left->n > nval)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bvalue > 1 && (*tree)->left->n < nval)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bvalue < -1 && (*tree)->right->n < nval)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (bvalue < -1 && (*tree)->right->n > nval)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}

/**
 * avl_insert -func to insert value into AVL.
 *
 * @tree: the root node of AVL tree.
 * @value: value of node
 *
 * Return: the inserted node,otherwise NULL.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_n = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);

		return (*tree);
	}
	r_insert_node(tree, *tree, &new_n, value);

	return (new_n);
}
