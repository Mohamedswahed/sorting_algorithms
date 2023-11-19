#include "sort.h"


/**
 * merge_arr_partion - To sort array partion.
 * @arr_partion: Array partion to sort.
 * @bufr: Memory to store the sorted divided array.
 * @first: The array first index.
 * @center: The array center index.
 * @last: The array last index.
 */
void merge_arr_partion(int *arr_partion,
		int *bufr, size_t first, size_t center,
		size_t last)
{
	size_t x, y, z = 0;

	printf("Merging...\n[left]: ");
	print_array(arr_partion + first, center - first);

	printf("[right]: ");
	print_array(arr_partion + center, last - center);

	for (x = first, y = center; x < center && y < last; z++)
		bufr[z] = (arr_partion[x] < arr_partion[y]) ?
			arr_partion[x++] : arr_partion[y++];
	for (; x < center; x++)
		bufr[z++] = arr_partion[x];
	for (; y < last; y++)
		bufr[z++] = arr_partion[y];
	for (x = first, z = 0; x < last; x++)
		arr_partion[x] = bufr[z++];

	printf("[Done]: ");
	print_array(arr_partion + first, last - first);
}

/**
 * merge_rec - To merge sort by recursion.
 * @arr_partion: Array partion to sort.
 * @bufr: A memory to store the sorted result.
 * @first: The first index of the subarray.
 * @last: The last index of the subarray.
 */
void merge_rec(int *arr_partion, int *bufr, size_t first, size_t last)
{
	size_t center;

	if (last - first > 1)
	{
		center = first + (last - first) / 2;
		merge_rec(arr_partion, bufr, first, center);
		merge_rec(arr_partion, bufr, center, last);
		merge_arr_partion(arr_partion, bufr, first, center, last);
	}
}

/**
 * merge_sort - Array ascending sort by merge sort.
 * @array: An Integers array.
 * @size: The array size.
 * Description: The top-down merge sort.
 */
void merge_sort(int *array, size_t size)
{
	int *bufr;

	if (size < 2 || array == NULL)
		return;

	bufr = calloc(size, sizeof(int));
	if (bufr == NULL)
		return;

	merge_rec(array, bufr, 0, size);

	free(bufr);
}
