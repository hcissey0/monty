#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a node at the specified index
 * @h: head of the list
 * @idx: the index
 * @n: the element
 *
 * Return: address of the new node or NULL on error
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i = 0;
	dlistint_t *ptr = *h, *tmp;

	if (h == NULL)
		return (NULL);
	tmp = malloc(sizeof(dlistint_t));
	if (tmp == NULL)
		return (NULL);
	tmp->n = n;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (idx == 0)
		return (add_dnodeint(h, n));
	while (ptr != NULL)
	{
		if (i == idx - 1)
		{
			if (ptr->next == NULL)
				return (add_dnodeint_end(h, n));
			tmp->next = ptr->next;
			tmp->prev = ptr;
			ptr->next->prev = tmp;
			ptr->next = tmp;
			return (tmp);
		}
		ptr = ptr->next;
		i++;
	}
	free(tmp);
	return (NULL);
}
