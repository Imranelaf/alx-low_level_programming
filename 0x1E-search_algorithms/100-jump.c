#include "search_algos.h"
#include <math.h>

/**
 * jump_search - Searches for a value in a sorted array of integers
 *               using the Jump search algorithm.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: index where the value is located or -1 if the value is not present.
 */
int jump_search(int *array, size_t size, int value)
{
	int index, x, y, prev;

	if (array == NULL || size == 0)
	{
		return (-1);
	}


	prev = index = 0;
	x = (int)sqrt((double)size);
	y = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", index, array[index]);

		if (array[index] == value)
		{
			return (index);
		}
		y++, prev = index,  index = y * x;
	} while (index < (int)size && array[index] < value);
	printf("Value found between indexes [%d] and [%d]\n", prev, index);
	for (; prev <= index && prev < (int)size; prev++)
	{
		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
		if (array[prev] == value)
		{
			return (prev);
		}
	}

	return (-1);
}
