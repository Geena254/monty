#include "monty.h"

/**
 * st_swap - This swap function swaps the top two elements of the stack.
 * @head: pointer to stack.
 * @count: line number in Monty ByteCodes file.
 * Return: Nothing.
*/
void st_swap(stack_t **head, unsigned int count)
{
	stack_t *second, *first;
	int temp;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		exitstatus = -1;
		return;
	}

	first = *head;
	second = first->next;
	temp = first->n;
	first->n = second->n;
	second->n = temp;
}
