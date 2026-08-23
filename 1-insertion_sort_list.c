#include "sort.h"

/**
 * insertion_sort_list - isert algorithm for a dub_link_list
 * @list: pointer to the head of the list
 * Return: null and void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node, *temp;

	if (!list || !(*list) || !(*list)->next)
		return;

	node = (*list)->next;
	while (node)
	{
		temp = node->next;
		while (node->prev && node->prev->n > node->n)
		{
			node->prev->next = node->next;
			if (node->next)
				node->next->prev = node->prev;

			node->next = node->prev;
			node->prev = node->prev->prev;
			if (node->prev)
				node->prev->next = node;
			else
				*list = node;

			node->next->prev = node;
			print_list(*list);
		}
		node = temp;
	}
}
