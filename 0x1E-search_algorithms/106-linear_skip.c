#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a skip list.
 *
 * @list: Input skip list.
 * @value: Value to search for.
 * Return: Pointer to the node containing the value or NULL if not found.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *c_node;

	if (list == NULL)
		return (NULL);

	c_node = list;

	do {
		list = c_node;
		c_node = c_node->express;
		printf("Value checked at index ");
		printf("[%d] = [%d]\n", (int)c_node->index, c_node->n);
	} while (c_node->express && c_node->n < value);

	if (c_node->express == NULL)
	{
		list = c_node;
		while (c_node->next)
			c_node = c_node->next;
	}

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)list->index, (int)c_node->index);

	while (list != c_node->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}

	return (NULL);
}
