#include "lists.h"

/**
 * dlistint_len - Returns the number of nodes in a doubly linked list
 * @h: Pointer to the head of the list
 *
 * Return: Number of nodes in the list
 */
size_t dlistint_len(const dlistint_t *h)
{
    const dlistint_t *n = h;	
    size_t count = 0;

    while (n != NULL)
    {
        count++;
        n = n->next;
    }

    return count;
}
