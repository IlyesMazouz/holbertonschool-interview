#include "binary_trees.h"
#include <stdlib.h>

/**
 * heapify_down - Moves a node down to maintain max heap property.
 * @node: Pointer to the node to heapify down.
 */
void heapify_down(heap_t *node)
{
heap_t *largest = node, *left = node->left, *right = node->right;
int temp;

if (left && left->n > largest->n)
largest = left;
if (right && right->n > largest->n)
largest = right;

if (largest != node)
{
temp = node->n;
node->n = largest->n;
largest->n = temp;
heapify_down(largest);
}
}

/**
 * height - Computes the height of a binary tree.
 * @tree: Pointer to the root.
 * Return: Height.
 */
int height(const binary_tree_t *tree)
{
int lh, rh;

if (!tree)
return (0);
lh = height(tree->left);
rh = height(tree->right);
return (1 + (lh > rh ? lh : rh));
}

/**
 * get_last_node - Returns the last inserted node in level order.
 * @tree: Pointer to root node.
 * @level: Level to search.
 * Return: Pointer to node.
 */
heap_t *get_last_node(heap_t *tree, int level)
{
heap_t *node = NULL;

if (!tree)
return (NULL);
if (level == 1)
return (tree);
node = get_last_node(tree->right, level - 1);
if (!node)
node = get_last_node(tree->left, level - 1);
return (node);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to root of heap.
 * Return: Value of root node or 0 on failure.
 */
int heap_extract(heap_t **root)
{
int value;
heap_t *last, *parent;

if (!root || !*root)
return (0);

value = (*root)->n;

if (!(*root)->left && !(*root)->right)
{
free(*root);
*root = NULL;
return (value);
}

last = get_last_node(*root, height(*root));
if (!last)
return (0);

(*root)->n = last->n;
parent = last->parent;

if (parent->left == last)
parent->left = NULL;
else
parent->right = NULL;

free(last);
heapify_down(*root);

return (value);
}
