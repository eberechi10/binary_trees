#ifndef _BINARY_TREES_H
#define _BINARY_TREES_H

#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;


size_t tree_s(const binary_tree_t *tree);
int *heap_to_sorted_array(heap_t *heap, size_t *size);
void heapify_h(heap_t *root);
heap_t *array_to_heap(int *array, size_t size);
heap_t *heap_insert(heap_t **root, int value);
size_t binary_tree_size(const binary_tree_t *tree);
int bt_helper(const binary_tree_t *tree);
int btc_helper(const binary_tree_t *tree, size_t index, size_t size);
int binary_tree_is_heap(const binary_tree_t *tree);
int binary_tree_is_complete(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
avl_t *sorted_array_to_avl(int *array, size_t size);
void sata_helper(avl_t **root, int *array, size_t lo, size_t hi);
void bal(avl_t **tree);
int b_successor(bst_t *node);
int remove_type(bst_t *root);
bst_t *bst_remove(bst_t *root, int value);
avl_t *avl_remove(avl_t *root, int value);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *node_a,
				const binary_tree_t *node_b);
void binary_tree_levelorder(const binary_tree_t *start, void (*process)(int));
int binary_tree_is_complete(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *root);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);
int is_bst_helper(const binary_tree_t *subtree, int lower_bound,
		int upper_bound);
bst_t *bst_insert(bst_t **tree, int value);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_find_min(bst_t *node);
bst_t *bst_remove(bst_t *root, int value);
size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_is_avl(const binary_tree_t *tree);
avl_t *avl_create_node(int value);
avl_t *avl_insert(avl_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
avl_t *avl_create_node(int value);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
void binary_tree_print(const binary_tree_t *tree);
void count_height(const binary_tree_t *tree, size_t height, size_t *max);
void count_nodes(const binary_tree_t *tree, size_t *size);
void print_at_level(const binary_tree_t *tree, void (*func)(int), int level);
int bt_is_complete(const binary_tree_t *tree, size_t index, size_t size);


#endif
