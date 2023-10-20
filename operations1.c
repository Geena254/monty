#include "monty.h"

/**
 * st_push - to push new element in the stack
 * @head: refrance to stack to push onit
 * @count: line number in Monty ByteCodes file.
 * Return: Nothing.
*/

void st_push(stack_t **head, unsigned int count)
{
	char *args = strtok(NULL, " \t\n");
	stack_t *new;

	if (args == NULL || !is_int(args))
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		exitstatus = -1;
		return;
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exitstatus = -1;
		return;
	}

	new->n = atoi(args);
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
}

/**
 * st_pall - Fucntion tht prints the stack
 * @head: beginning of stack
 * @count: line number in Monty ByteCodes file.
 * Return: Nothing.
 */

void st_pall(stack_t **head, unsigned int count)
{
	stack_t *he;
	(void)count;

	he = *head;
	if (he == NULL || *head == NULL)
		return; /* Stack is empty */

	while (he != NULL)
	{
		printf("%d\n", he->n);
		he = he->next;
	}
}
