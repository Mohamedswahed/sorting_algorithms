#include "sort.h"


/**
 * swap_forward - Doubly-linked list swap node front of it.
 * @ptr_dl_head: Doubly-linked list head pointer.
 * @ptr_dl_tail: Doubly-linked list tail pointer.
 * @ptr_curr_swp: Current swapping node pointer.
 */
void swap_forward(listint_t **ptr_dl_head,
		listint_t **ptr_dl_tail, listint_t **ptr_curr_swp)
{
	listint_t *temperary = (*ptr_curr_swp)->next;

	if ((*ptr_curr_swp)->prev != NULL)
		(*ptr_curr_swp)->prev->next = temperary;
	else
		*ptr_dl_head = temperary;
	temperary->prev = (*ptr_curr_swp)->prev;
	(*ptr_curr_swp)->next = temperary->next;
	if (temperary->next != NULL)
		temperary->next->prev = *ptr_curr_swp;
	else
		*ptr_dl_tail = *ptr_curr_swp;
	(*ptr_curr_swp)->prev = temperary;
	temperary->next = *ptr_curr_swp;
	*ptr_curr_swp = temperary;
}

/**
 * swap_backward - Doubly-linked list swap node behind it.
 * @ptr_dl_head: Doubly-linked list head pointer.
 * @ptr_dl_tail: Doubly-linked list tail pointer.
 * @ptr_curr_swp: Current swapping node pointer.
 */
void swap_backward(listint_t **ptr_dl_head,
		listint_t **ptr_dl_tail, listint_t **ptr_curr_swp)
{
	listint_t *temperary = (*ptr_curr_swp)->prev;

	if ((*ptr_curr_swp)->next != NULL)
		(*ptr_curr_swp)->next->prev = temperary;
	else
		*ptr_dl_tail = temperary;
	temperary->next = (*ptr_curr_swp)->next;
	(*ptr_curr_swp)->prev = temperary->prev;
	if (temperary->prev != NULL)
		temperary->prev->next = *ptr_curr_swp;
	else
		*ptr_dl_head = *ptr_curr_swp;
	(*ptr_curr_swp)->next = temperary;
	temperary->prev = *ptr_curr_swp;
	*ptr_curr_swp = temperary;
}

/**
 * cocktail_sort_list -  Doubly-linked list sort ascending order
 * by cocktail algorithm.
 * @list: Doubly-linked list head pointer.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *t, *ptr_curr_swp;
	bool not_yet_done = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (t = *list; t->next != NULL;)
		t = t->next;

	while (not_yet_done == false)
	{
		not_yet_done = true;
		for (ptr_curr_swp = *list;
				ptr_curr_swp != t;
				ptr_curr_swp = ptr_curr_swp->next)
		{
			if (ptr_curr_swp->n > ptr_curr_swp->next->n)
			{
				swap_forward(list, &t, &ptr_curr_swp);
				print_list((const listint_t *)*list);
				not_yet_done = false;
			}
		}
		for (ptr_curr_swp = ptr_curr_swp->prev; ptr_curr_swp != *list;
				ptr_curr_swp = ptr_curr_swp->prev)
		{
			if (ptr_curr_swp->n < ptr_curr_swp->prev->n)
			{
				swap_backward(list, &t, &ptr_curr_swp);
				print_list((const listint_t *)*list);
				not_yet_done = false;
			}
		}
	}
}
