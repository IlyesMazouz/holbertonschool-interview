#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @head: pointer to the head of the skip list
 * @value: value to search for
 *
 * Return: pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
skiplist_t *node, *prev;

if (head == NULL)
return (NULL);

node = head;

while (node->express && node->express->n < value)
{
printf("Value checked at index [%lu] = [%d]\n",
node->express->index, node->express->n);
node = node->express;
}

if (node->express)
{
printf("Value checked at index [%lu] = [%d]\n",
node->express->index, node->express->n);
prev = node;
node = node->express;
}
else
{
prev = node;
while (node->next)
node = node->next;
}

printf("Value found between indexes [%lu] and [%lu]\n",
prev->index, node->index);

for (; prev && prev->index <= node->index; prev = prev->next)
{
printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
if (prev->n == value)
return (prev);
}

return (NULL);
}
