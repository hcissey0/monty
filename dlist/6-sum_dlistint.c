#include "lists.h"

/**
 * sum_dlistint - sums up a doubly linked list
 * @head: head of the list
 *
 * Return: the sum of the list
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *ptr = head;

	while (ptr && ptr->prev)
		ptr = ptr->prev;
	while (ptr != NULL)
	{
		sum += ptr->n;
		ptr = ptr->next;
	}

	return (sum);
}
