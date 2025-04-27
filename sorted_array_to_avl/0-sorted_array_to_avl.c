#include "binary_trees.h"
#include <stdlib.h>

/**
 * create_node - Creates a new AVL node
 * @parent: Pointer to the parent node
 * @n: Integer value for the new node
 *
 * Return: Pointer to the new node
 */
avl_t *create_node(avl_t *parent, int n)
{
avl_t *new_node = malloc(sizeof(avl_t));

if (!new_node)
return (NULL);

new_node->n = n;
new_node->parent = parent;
new_node->left = NULL;
new_node->right = NULL;

return (new_node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: The number of elements in the array
 *
 * Return: Pointer to the root node of the AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
if (size == 0)
return (NULL);

size_t mid = size / 2;
avl_t *root = create_node(NULL, array[mid]);

if (!root)
return (NULL);

root->left = sorted_array_to_avl(array, mid);
if (root->left)
root->left->parent = root;

root->right = sorted_array_to_avl(array + mid + 1, size - mid - 1);
if (root->right)
root->right->parent = root;

return (root);
}
