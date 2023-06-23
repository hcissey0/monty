#include "lists.h"

/**
 * dlistint_len - returns the length of a doubly linked list
 * @h: head of the list
 *
 * Return: number of elements in the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t n = 0;
	const dlistint_t *ptr = h;

	while (ptr && ptr->prev)
		ptr = ptr->prev;
	while (ptr != NULL)
	{
		n++;
		ptr = ptr->next;
	}
	return (n);
}
