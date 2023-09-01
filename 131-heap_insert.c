#include "binary_trees.h"

/**
 * heap_insert - func to insert value into max binary heap.
 *
 * @root: root node of the heap.
 * @value: value to be inserted.
 *
 * Return: the node, otherwise Null.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *tree, *flip;
	int size, sub, leaves, elm, bt, level;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;
	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	for (bt = 1 << (level - 1); bt != 1; bt >>= 1)
		tree = leaves & bt ? tree->right : tree->left;

	new = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new) : (tree->left = new);

	flip = new;

	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		elm = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = elm;
		new = new->parent;
	}
	return (new);
}


/**
 * binary_tree_size - func to count size binary tree.
 *
 * @tree: the tree to count.
 *
 * Return: size of tree, otherwise Null.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)

		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
