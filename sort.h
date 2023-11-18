#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * enum bool - To enumerate a Boolean values.
 * @false: Equal 0.
 * @true: Equal 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;
/**
 * struct listint_s - Doubly linked list node
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* given functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* my function */
void bubble_sort(int *array, size_t size);
void swap_int_nums(int *x, int *y);
void insertion_sort_list(listint_t **list);
int do_part(int *array, size_t size, int first, int last);
void sort_it(int *array, size_t size, int first, int last);
void quick_sort(int *array, size_t size);

#endif /* SORT_H */
