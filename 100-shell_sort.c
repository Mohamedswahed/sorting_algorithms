#include "sort.h"

/**
 * swap_integer - Swap two integers in an array.
 * @a: The first index to be swaped
 * @b: The second index to be swaped
 */
void swap_integer(int *x, int *y)
{
	int t;

	t = *x;
	*x = *y;
	*y = t;
}

/**
 * shell_sort - Sorts an array using the shell sort algorithm.
 * @array: An array of integers to be sorted
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t x, i, j;

	if (array == NULL || size < 2)
		return;

	for (x = 1; x < (size / 3);)
		x = x * 3 + 1;

	for (; x >= 1; x /= 3)
	{
		for (i = x; i < size; i++)
		{
			j = i;
			while (j >= x && array[j - x] > array[j])
			{
				swap_integer(array + j, array + (j - x));
				j -= x;
			}
		}
		print_array(array, size);
	}
}
