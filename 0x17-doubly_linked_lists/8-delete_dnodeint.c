#include "lists.h"

/**
 * deletes the node at index of a dlistint_t linked list
 * @head: double pointer to the head of the list
 * @index: index of the node to delete
 *
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current_node, *temp_node;
	unsigned int i;

	if (*head == NULL)
		return (-1);
	current_node = *head;
	if (index == 0)
	{
		*head = current_node->next;
		free(current_node);
		if (*head != NULL)
			(*head)->prev = NULL;
		return (1);
	}
	for (i = 0; current_node != NULL && i < index; i++)
		current_node = current_node->next;
	if (current_node == NULL)
		return (-1);
	temp_node = current_node;
	current_node->prev->next = current_node->next;
	if (current_node->next != NULL)
		current_node->next->prev = current_node->prev;
	free(temp_node);
	return (1);
}
