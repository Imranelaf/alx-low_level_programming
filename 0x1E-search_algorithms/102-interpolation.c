#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers
 *               using the Jump search algorithm.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: index where the value is located or -1 if the value is not present.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t i, l, h;
	double f;

	if (array == NULL)
		return (-1);

	l = 0;
	h = size - 1;

	while (size)
	{
		f = (double)(h - l) / (array[h] - array[l]) * (value - array[l]);
		i = (size_t)(l + f);
		printf("Value checked array[%d]", (int)i);

		if (i >= size)
		{
			printf(" is out of range\n");
			break;
		}
		else
		{
			printf(" = [%d]\n", array[i]);
		}

		if (array[i] == value)
			return ((int)i);

		if (array[i] < value)
			l = i + 1;
		else
			h = i - 1;

		if (l == h)
			break;
	}

	return (-1);
}
