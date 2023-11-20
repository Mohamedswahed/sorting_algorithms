#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void integers_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - sort the list and print the changes
 * @array: The array to sort.
 * @size: Size of the array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t h = 0,  i, j;

	if (size < 2)
		return;

	while (h <= size / 3)
		h = h * 3 + 1;

	while (h >= 1)
	{
		for (i = h; i < size; i++)
			for (j = i; j >= h && array[j] < array[j - h]; j -= h)
				intergers_swap(array, j, j - h);
		h /= 3;
		print_array(array, size);
	}
}
