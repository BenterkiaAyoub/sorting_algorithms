#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @h: A pointer to the head of the doubly linked list.
 * @node1: A pointer to the first node to be swapped.
 * @node2: The second node to be swapped.
 */
void swap_nodes(listint_t **h, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*h = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly linked list of integers.
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *itr, *insrt, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (itr = (*list)->next; itr != NULL; itr = tmp)
	{
		tmp = itr->next;
		insrt = itr->prev;
		while (insrt != NULL && itr->n < insrt->n)
		{
			swap_nodes(list, &insrt, itr);
			print_list((const listint_t *)*list);
		}
	}
}
