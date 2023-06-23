#include "lists.h"

/**
 * free_dlistint - frees a doubly linked list
 * @head: head of the list
 *
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *ptr, *tmp;

	ptr = head;
	while (ptr && ptr->prev)
		ptr = ptr->prev;
	while (ptr != NULL)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
}
