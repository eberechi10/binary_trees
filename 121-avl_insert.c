#include "binary_trees.h"
/**
 * avl_create_node - Create a new AVL node
 * @value: The value to store in the new node
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_create_node(int value)
{
	avl_t *new_node = malloc(sizeof(avl_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = NULL;
	new_node->height = 1;
	return (new_node);
}
/**
 * avl_insert - Insert a value into an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: The value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = avl_create_node(value);
		return (*tree);
	}
	if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert(&((*tree)->left), value);
		(*tree)->left->parent = *tree;
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_insert(&((*tree)->right), value);
		(*tree)->right->parent = *tree;
	}
	else
	{
		return (NULL);
	}
	(*tree)->height = 1 + MAX(avl_height((*tree)->left),
			avl_height((*tree)->right));
	int balance = avl_balance_factor(*tree);

	if (balance > 1 && value < (*tree)->left->n)
		return (avl_rotate_right(*tree));
	if (balance < -1 && value > (*tree)->right->n)
		return (avl_rotate_left(*tree));
	if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = avl_rotate_left((*tree)->left);
		return (avl_rotate_right(*tree));
	}
	if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = avl_rotate_right((*tree)->right);
		return (avl_rotate_left(*tree));
	}
	return (*tree);
}
