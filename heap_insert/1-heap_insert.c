#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 *
 * @root: Double pointer to the root of the Max Heap
 * @value: The value to insert
 *
 * Return: Pointer to the newly inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
heap_t *node;

if (!root)
return (NULL);

node = binary_tree_node(NULL, value);
if (!node)
return (NULL);

if (*root == NULL)
{
*root = node;
return (node);
}

while (node->parent && node->n > node->parent->n)
{
int temp = node->n;
node->n = node->parent->n;
node->parent->n = temp;

node = node->parent;
}

return (node);
}
