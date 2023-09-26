#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: pointer to the head of the list
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	int swap = 0;
	listint_t *previous, *rev_curser, *curser, *following;

	for (curser = *list; curser; curser = following)
	{
		following = curser->next;
		if (!following)
			break;
		if (curser->next->n < curser->n)
		{
			rev_curser = curser->next;
			while (rev_curser->prev && (rev_curser->prev->n > rev_curser->n))
			{
				if (rev_curser->prev->prev)
					rev_curser->prev->prev->next = rev_curser;
				else
					*list = rev_curser;
				previous = rev_curser->prev->prev;
				rev_curser->prev->prev = rev_curser;
				rev_curser->prev->next = rev_curser->next;
				if (rev_curser->next)
					rev_curser->next->prev = rev_curser->prev;
				rev_curser->next = rev_curser->prev;
				rev_curser->prev = previous;
				swap += 1;
				if (swap == 1)
					following = rev_curser->next;
				print_list(*list);
			}
			swap = 0;
		}
	}
}
