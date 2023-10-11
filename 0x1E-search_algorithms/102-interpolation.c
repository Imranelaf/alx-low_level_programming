#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array of integers
 * using the Interpolation search algorithm.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The first index where the value is located or -1 if the value is
 * not present in the array or if the array is NULL.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t index, low, high;

	if (array == NULL)
	{
		return (-1);
	}

	for (low = 0, high = size - 1; high >= low;)
	{
		index = low + (((double)(high - low) / (array[high] - array[low])) * (value - array[low]));
		if (index < size)
		{
			printf("Value checked array[%ld] = [%d]\n", index, array[index]);
		}
		else
		{
			printf("Value checked array[%ld] is out of range\n", index);
			break;
		}

		if (array[index] == value)
		{
			return (index);
		}
		if (array[index] > value)
		{
			high = index - 1;
		}
		else
		{
			low = index + 1;
		}
	}
	return (-1);
}
