#include "sort.h"


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
 * DoHorPart - Order a subset array by hoare partition.
 * @array: An integers array.
 * @size: The array size.
 * @first: The first index of subset.
 * @last: The last index of subset.
 * Return: The index for the final partition.
 * Description: makes subset last element pivot,array Printing after each swap.
 */
int DoHorPart(int *array, size_t size, int first, int last)
{
	int pvt, a, b;

	pvt = array[last];
	for (a = first - 1, b = last + 1; a < b;)
	{
		do {
			a++;
		} while (array[a] < pvt);
		do {
			b--;
		} while (array[b] > pvt);

		if (a < b)
		{
			swap_int_nums(array + a, array + b);
			print_array(array, size);
		}
	}

	return (a);
}

/**
 * HorSorting - Recursion version of quick sort.
 * @array: An integers array.
 * @size: The array size.
 * @first: The Array first index.
 * @last: The array last index.
 *
 * Description: Applying Hoare partition.
 */
void HorSorting(int *array, size_t size, int first, int last)
{
	int p;

	if (last - first > 0)
	{
		p = DoHorPart(array, size, first, last);
		HorSorting(array, size, first, p - 1);
		HorSorting(array, size, p, last);
	}
}

/**
 * quick_sort_hoare - Ascending Sort array by quicksort algorithm.
 * @array: Integers array.
 * @size: The array size.
 * Description: Applying Hoare partition and Printing
 * the array after each swap.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;

	HorSorting(array, size, 0, size - 1);
}
