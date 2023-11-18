#include "sort.h"
/**
 * swap_lst - function to swap two nodes in the list
 * @x:  adress of the first node
 * @y:  adress of the next node
 * Return: void
 */
void swap_lst(listint_t *x, listint_t *y)
{
	if (x == NULL || y == NULL || x == y)
		return;
	if (x->prev)
	{
		(x->prev)->next = y;
	}
	if (y->next)
	{
		(y->next)->prev = x;
	}
	x->next = y->next;
	y->prev = x->prev;
	x->prev = y;
	y->next = x;
}
/**
 * insertion_sort_list -  using the Insertion sort algorithm
 * sorts a doubly linked list of integers in ascending order
 * @list: list to be sorted doubly linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	listint_t *i, *j;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	i = (*list)->next;
	while (i)
	{
		j = i;
		i = i->next;
		while (j && j->prev)
		{
			if (j->prev->n > j->n)
			{
				swap_lst(j->prev, j);
				if (!j->prev)
					*list = j;
				print_list((const listint_t *)*list);
			}
			else
				j = j->prev;
		}

	}

}

