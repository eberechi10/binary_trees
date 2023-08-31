#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: Double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    /* If the tree is empty, create a new node and make it the root */
    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        if (*tree == NULL)
            return (NULL);
        return (*tree);
    }

    /* If the value is already present, ignore it */
    if (value == (*tree)->n)
        return (NULL);

    /* If the value is less than the current node's value, insert in the left subtree */
    if (value < (*tree)->n)
    {
        if ((*tree)->left == NULL)
        {
            (*tree)->left = binary_tree_node(*tree, value);
            if ((*tree)->left == NULL)
                return (NULL);
            return ((*tree)->left);
        }
        return (bst_insert(&((*tree)->left), value));
    }

    /* If the value is greater than the current node's value, insert in the right subtree */
    if (value > (*tree)->n)
    {
        if ((*tree)->right == NULL)
        {
            (*tree)->right = binary_tree_node(*tree, value);
            if ((*tree)->right == NULL)
                return (NULL);
            return ((*tree)->right);
        }
        return (bst_insert(&((*tree)->right), value));
    }

    return (NULL); /* This line should never be reached, but added for completeness */
}

