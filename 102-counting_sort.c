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
	int *c, *s, m, i;

	if (array == NULL || size < 2)
		return;

	s = malloc(sizeof(int) * size);
	if (s == NULL)
		return;
	m = get_maximum(array, size);
	c = malloc(sizeof(int) * (m + 1));
	if (c == NULL)
	{
		free(s);
		return;
	}

	for (i = 0; i < (m + 1); i++)
		c[i] = 0;
	for (i = 0; i < (int)size; i++)
		c[array[i]] += 1;
	for (i = 0; i < (m + 1); i++)
		c[i] += c[i - 1];
	print_array(c, m + 1);

	for (i = 0; i < (int)size; i++)
	{
		s[c[array[i]] - 1] = array[i];
		c[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = s[i];

	free(s);
	free(c);
}
