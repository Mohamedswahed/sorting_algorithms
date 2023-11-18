#include "sort.h"

void swap_int_nums(int *x, int *y);
int do_part(int *array, size_t size, int first, int last);
void sort_it(int *array, size_t size, int first, int last);
void quick_sort(int *array, size_t size);

/**
 * swap_int_nums - To swap two integer numbers.
 * @x: First integer number.
 * @y: Second integer number.
 */
void swap_int_nums(int *x, int *y)
{
	int p;

	p = *x;
	*x = *y;
	*y = p;
}

/**
 * do_part - Order a subset array of integers (last element as pivot).
 * @array: Integers array.
 * @size: Array size.
 * @first: First index of subset.
 * @last: Last index of subset.
 * Return: The index of final partition
 */
int do_part(int *array, size_t size, int first, int last)
{
	int *pvt, a, b;

	pvt = array + last;
	for (a = b = first; b < last; b++)
	{
		if (array[b] < *pvt)
		{
			if (a < b)
			{
				swap_int_nums(array + b, array + a);
				print_array(array, size);
			}
			a++;
		}
	}

	if (array[a] > *pvt)
	{
		swap_int_nums(array + a, pvt);
		print_array(array, size);
	}

	return (a);
}

/**
 * sort_it - Quicksort by recursion.
 * @array: Integers array to be sorted.
 * @size: The array size.
 * @first: Array first index.
 * @last: Array last index.
 * Description: Applying do_part.
 */
void sort_it(int *array, size_t size, int first, int last)
{
	int p;

	if (last - first > 0)
	{
		p = do_part(array, size, first, last);
		sort_it(array, size, first, p - 1);
		sort_it(array, size, p + 1, last);
	}
}

/**
 * quick_sort - Sort an Array ascending sort by quick sort algorithm.
 * @array: An array of integers.
 * @size: The array size.
 * Description: Applying do_part.
 * Array printing after two elements swaped.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_it(array, size, 0, size - 1);
}
