 #include "lists.h"

/**
 * print_dlistint - prints a doubly linked list
 * @h: head of the list
 *
 * Return: number of printed nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t i = 0;
	const dlistint_t *ptr = h;

	while (ptr && ptr->prev)
		ptr = ptr->prev;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
		i++;
	}
	return (i);
}
