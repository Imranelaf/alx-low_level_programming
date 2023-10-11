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
	listint_t *current, *jump;
	size_t jump, step_s;

	if (list == NULL || size == 0)
	{
		return (NULL);
	}

	jump = 0;
	step_s = sqrt(size);
	for (current = jump = list; jump->index + 1 < size && jump->n < value;)
	{
		current = jump;
		for (jump += step_s; jump->index < jump; jump = jump->next)
		{
			if (jump->index + 1 == size)
			{
				break;
			}
		}
		printf("Value checked at index [%ld] = [%d]\n", jump->index, jump->n);
	}
	printf("Value found between indexes [%ld] and [%ld]\n",
			current->index, jump->index);
	for (; current->index < jump->index && current->n < value; current = current->next)
		printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);
	printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);
	return (current->n == value ? current : NULL);
}
