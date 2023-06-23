#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes a nodeint at a specified index
 * @head: head of the list
 * @index: index of the element
 *
 * Return: 1 if succeeded, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *ptr = *head;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		*head = ptr->next;
		if (ptr->next != NULL)
			ptr->next->prev = NULL;
		free(ptr);
		return (1);
	}

	for (i = 0; i < index && ptr != NULL; i++)
		ptr = ptr->next;
	if (ptr == NULL)
		return (-1);
	if (ptr->next != NULL)
		ptr->next->prev = ptr->prev;
	if (ptr->prev != NULL)
		ptr->prev->next = ptr->next;
	free(ptr);
	return (1);
}
