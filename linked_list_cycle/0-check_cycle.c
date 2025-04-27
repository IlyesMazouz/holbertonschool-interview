#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle
 * @list: pointer to the head of the list
 * Return: 0 if no cycle, 1 if there's a cycle
 */
int check_cycle(listint_t *list)
{
    listint_t *slow = list, *fast = list;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;         // Move slow pointer by one step
        fast = fast->next->next;   // Move fast pointer by two steps

        if (slow == fast)          // If the two pointers meet, a cycle exists
            return (1);
    }

    return (0);  // No cycle found
}
