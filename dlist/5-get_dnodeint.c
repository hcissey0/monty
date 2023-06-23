#include "lists.h"

/**
 * get_dnodeint_at_index - gets a node at a given index
 * @head: head of the list
 * @index: the index
 *
 * Return: address of the node if found, otherwise NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int n = 0;
	dlistint_t *ptr = head;

	while (ptr && ptr->prev)
		ptr = ptr->prev;
	while (ptr != NULL)
	{
		if (index == n)
			return (ptr);
		n++;
		ptr = ptr->next;
	}

	return (NULL);
}
