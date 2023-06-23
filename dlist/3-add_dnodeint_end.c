#include "lists.h"

/**
 * add_dnodeint_end - adds a node at the end of a list
 * @head: head of the list
 * @n: element to add
 *
 * Return: address of the added node
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *ptr = *head;
	dlistint_t *tmp;

	while (ptr && ptr->next)
		ptr = ptr->next;
	tmp = malloc(sizeof(dlistint_t));
	if (tmp == NULL)
		return (NULL);
	tmp->n = n;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (*head == NULL)
	{
		*head = tmp;
		return (tmp);
	}
	ptr->next = tmp;
	tmp->prev = ptr;

	return (tmp);
}
