#include "search_algos.h"
#include <math.h>

/**
 * jump_list - Searches for a value in a sorted list of integers using the
 * Jump search algorithm.
 *
 * @list: Pointer to the head of the list to search in.
 * @size: Number of nodes in the list.
 * @value: Value to search for.
 *
 * Return: Pointer to the first node where the value is located, or NULL if the
 * value is not present in the list or if the list is NULL.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	listint_t *prev, *jump;
	size_t x, y;

	if (list == NULL || size == 0)
	{
		return (NULL);
	}

	x = 0;
	y = sqrt(size);
	for (prev = jump = list; jump->index + 1 < size && jump->n < value;)
	{
		prev = jump;
		for (x += y; jump->index < x; jump = jump->next)
		{
			if (jump->index + 1 == size)
			{
				break;
			}
		}
		printf("Value checked at index [%ld] = [%d]\n", jump->index, jump->n);
	}
	printf("Value found between indexes [%ld] and [%ld]\n",
			prev->index, jump->index);
	for (; prev->index < jump->index && prev->n < value; prev = prev->next)
		printf("Value checked at index [%ld] = [%d]\n", prev->index, prev->n);
	printf("Value checked at index [%ld] = [%d]\n", prev->index, prev->n);
	return (prev->n == value ? prev : NULL);
}
