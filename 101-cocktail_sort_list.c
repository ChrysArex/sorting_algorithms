#include "sort.h"

/**
 * swap_nodes - swap two nodes of a doubly linked list
 *
 * @list: doubly linked list
 * @front: node to swap with previous node
 *
 * Return: nothing
 */
void swap_nodes(listint_t **list, listint_t *front)
{
	listint_t *previous;

	if (front->prev->prev)
		front->prev->prev->next = front;
	else
		*list = front;
	previous = front->prev->prev;
	front->prev->prev = front;
	front->prev->next = front->next;

	if (front->next)
		front->next->prev = front->prev;
	front->next = front->prev;
	front->prev = previous;
}

/**
 * cocktail_sort_list - sorts a doubly linked list using the
 * Cocktail shaker sort algorithm
 *
 * @list: pointer to first node of doubly linked list
 *
 * Return: nothing
 */
void cocktail_sort_list(listint_t **list)
{
	int swap = 1;
	listint_t *current, *following;

	while (swap)
	{
		swap = 0;
		for (current = *list; current; current = following)
		{
			following = current->next;
			if (!current->next)
				break;
			if (current->n > current->next->n)
			{
				swap_nodes(list, current->next);
				swap += 1;

				print_list(*list);
			}
		}

		if (swap == 0)
			break;

		for (; current; current = following)
		{
			following = current->prev;
			if (!current->prev)
				break;
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current);
				swap += 1;

				print_list(*list);
			}
		}
	}
}
