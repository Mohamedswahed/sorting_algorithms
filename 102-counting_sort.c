#include "sort.h"

/**
 * get_maximum - function to get the maximum value of array.
 * @array: array of integers.
 * @size: size of array.
 *
 * Return: The maximum number in array.
 */
int get_maximum(int *array, int size)
{
	int x, y;

	for (x = array[0], y = 1; y < size; y++)
	{
		if (array[y] > x)
			x = array[y];
	}

	return (x);
}

/**
 * counting_sort -function to count sort an array
 *                 using the counting sort algorithm.
 * @array: Array of integers.
 * @size: size of the array.
 *
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_maximum(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
