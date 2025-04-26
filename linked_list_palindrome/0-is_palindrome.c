#include "lists.h"
#include <stddef.h>


/**
 * reverse_list - Reverses a singly linked list
 * @head: pointer to pointer to head
 * Return: new head
 */
listint_t *reverse_list(listint_t *head)
{
listint_t *prev = NULL, *next = NULL;

while (head)
{
next = head->next;
head->next = prev;
prev = head;
head = next;
}
return (prev);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to head
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
listint_t *slow, *fast, *second_half, *copy_second_half;
    
if (!head || !(*head) || !(*head)->next)
return (1);

slow = *head;
fast = *head;

while (fast && fast->next)
{
slow = slow->next;
fast = fast->next->next;
}

second_half = reverse_list(slow);
copy_second_half = second_half;

    while (second_half)
    {
        if ((*head)->n != second_half->n)
        {
            reverse_list(copy_second_half);
            return (0);
        }
        *head = (*head)->next;
        second_half = second_half->next;
    }

    reverse_list(copy_second_half);
    return (1);
}
