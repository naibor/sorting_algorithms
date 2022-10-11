#include "sort.h"

/**
 * insertion_sort_list - Function
 * Description: sorts a doubly linked list of ints in ascending
 * using insertion
 * @list: the list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node = NULL, *temp = NULL;

	/*check for empty list and return*/
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	node = *list;
	node = node->next;

	/*check and sort list*/
	while (node)
	{
		while (node->prev && node->n < (node->prev)->n)
		{
			temp = node;
			if (node->next)
				(node->next)->prev = temp->prev;
			(node->prev)->next = temp->next;
			node = node->prev;
			temp->prev = node->prev;
			temp->next = node;
			if (node->prev)
				(node->prev)->next = temp;
			node->prev = temp;
			if (temp->prev == NULL)
				*list = temp;
			print_list(*list);
			node = node->prev;
		}
		node = node->next;
	}
}
