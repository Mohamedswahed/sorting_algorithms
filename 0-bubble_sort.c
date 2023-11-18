#include "sort.h"

/**
 * swap_int_nums - To Swap two integer numbers.
 * @x: The first integer number.
 * @y: The second integer number.
 */
void swap_int_nums(int *x, int *y)
{
	int p;

	p = *x;
	*x = *y;
	*y = p;
}

/**
 * bubble_sort - To Sort an array of integer numbers.
 * @array: Integers arrat to be sorted.
 * @size: Integers array size.
 * Description: To Print the array after each step.
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, length = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (x = 0; x < length - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				swap_int_nums(array + x, array + x + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		length--;
	}
}
