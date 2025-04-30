#include "binary_trees.h"
#include <limits.h>

/**
 * check_bst - Helper function to check if the tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum allowed value for the node
 * @max: Maximum allowed value for the node
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int check_bst(const binary_tree_t *tree, int min, int max)
{
if (!tree)
return (1);
if (tree->n <= min || tree->n >= max)
return (0);
return (check_bst(tree->left, min, tree->n) &&
check_bst(tree->right, tree->n, max));
}

/**
 * height - Helper function to compute the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree, or -1 if the tree is not balanced
 */
int height(const binary_tree_t *tree)
{
int left_height, right_height;

if (!tree)
return (0);

left_height = height(tree->left);
if (left_height == -1)
return (-1);

right_height = height(tree->right);
if (right_height == -1)
return (-1);

if (abs(left_height - right_height) > 1)
return (-1);

return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
if (!tree)
return (0);

if (!check_bst(tree, INT_MIN, INT_MAX))
return (0);

if (height(tree) == -1)
return (0);

return (1);
}

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: Pointer to the parent node of the node to create
 * @value: Integer value to store in the node
 * 
 * Return: A pointer to the newly created node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *new_node;

new_node = malloc(sizeof(binary_tree_t));
if (!new_node)
return (NULL);

new_node->n = value;
new_node->parent = parent;
new_node->left = NULL;
new_node->right = NULL;

return (new_node);
}
