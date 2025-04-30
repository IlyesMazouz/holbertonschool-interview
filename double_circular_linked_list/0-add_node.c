#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * create_node - Creates a new node with a duplicated string
 * @str: String to duplicate
 * Return: Pointer to new node or NULL
 */
static List *create_node(char *str)
{
List *node = malloc(sizeof(List));

if (!node)
return (NULL);
node->str = strdup(str);
if (!node->str)
{
free(node);
return (NULL);
}
node->next = node;
node->prev = node;
return (node);
}

/**
 * add_node_end - Adds a new node to the end of a double circular linked list
 * @list: Pointer to pointer to the head of the list
 * @str: String to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
List *node = create_node(str);

if (!node)
return (NULL);

if (!list || !*list)
{
*list = node;
}
else
{
List *tail = (*list)->prev;

node->next = *list;
node->prev = tail;
tail->next = node;
(*list)->prev = node;
}
return (node);
}

/**
 * add_node_begin - Adds a new node to the beginning of a double circular list
 * @list: Pointer to pointer to the head of the list
 * @str: String to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
List *node = create_node(str);

if (!node)
return (NULL);

if (!list || !*list)
{
*list = node;
}
else
{
List *tail = (*list)->prev;

node->next = *list;
node->prev = tail;
tail->next = node;
(*list)->prev = node;
*list = node;
}
return (node);
}
