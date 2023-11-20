#include "sort.h"
#include <stdio.h>


/**
 * selection_sort - function that sorts an array using sort algoritm.
 * @array: The array that to be sorted
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t x, y, z;
	int tmp;

	for (y = 0; y < size - 1; y++)
	{
		z = y;
		for (x = y + 1; x < size; x++)
		{
			if (array[x] < array[z])
				z = x;
		}

		if (z != y)
		{
			tmp = array[y];
			array[y] = array[z];
			array[z] = tmp;
			print_array(array, size);
		}
	}
}
