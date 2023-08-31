#include "binary_trees.h"

/**
 * bal - counts the balance of a AVL.
 *
 * @tree: tree.
 *
 * Return: balanced factor
 */
void bal(avl_t **tree)
{
	int bvalue;

	if (tree == NULL || *tree == NULL)
		return;

	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;

	bal(&(*tree)->left);
	bal(&(*tree)->right);

	bvalue = binary_tree_balance((const binary_tree_t *)*tree);

	if (bvalue > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bvalue < -1)

		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}


/**
 * b_successor - func to retrive successor node in the right subtree.
 *
 * @node: tree.
 *
 * Return: value of tree
 */
int b_successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = b_successor(node->left);
		if (left == 0)

		{
			return (node->n);
		}

		return (left);
	}

}


/**
 *remove_type - remove nodes children.
 *
 *@root: node.
 *
 *Return: 0 if success or otherwise
 */
int remove_type(bst_t *root)
{
	int new_v = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_v = b_successor(root->right);
		root->n = new_v;
		return (new_v);
	}
}


/**
 * avl_remove - function to remove the node from the AVL tree.
 *
 * @root: the root of the tree
 * @value: node value to be remove.
 *
 * Return: the currrent tree state.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_my = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);

	bal(&root_my);

	return (root_my);
}


/**
 * bst_remove - function to remove node from the BST tree
 *
 * @root: root of the tree
 * @value: node value.
 *
 * Return: current tree.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		bst_remove(root->left, value);

	else if (value > root->n)
		bst_remove(root->right, value);

	else if (value == root->n)

	{
		type = remove_type(root);

		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}


