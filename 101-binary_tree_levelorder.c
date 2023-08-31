#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @start: Pointer to the root node of the tree to traverse.
 * @process: Pointer to a function to call for each node.
 *
 * Description: This function traverses the binary tree using level-order
 * (breadth-first) traversal and calls the provided function for each node.
 * If root or action is NULL, the function does nothing.
 */
void binary_tree_levelorder(const binary_tree_t *start, void (*process)(int))
{
	if (start == NULL || process == NULL)
		return;

	binary_tree_t *queue[1000];
	int front = 0, rear = 0;
	binary_tree_t *current;

	queue[rear++] = (binary_tree_t *)start;

	while (front < rear)
	{
		current = queue[front++];
		process(current->n);

		if (current->left != NULL)
			queue[rear++] = current->left;

		if (current->right != NULL)
			queue[rear++] = current->right;
	}
}
