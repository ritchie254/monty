#include "ritchie.h"
/**
 * queue - set data structure of queue
 * @stack: stack
 * @line_number: line number or the command
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global->status = 1;
}
/**
 * stack - set data structure of stack
 * @stack: stack
 * @line_number: line number or the command
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global->status = 0;
}
/**
 * add_node_stack - add element at the top of the stack
 * Return: new_element address
 */
stack_t *add_node_stack(void)
{
	stack_t *new_element = NULL;

	new_element = malloc(sizeof(stack_t));
	if (new_element == NULL)
		exit(error_display(2));

	new_element->n = atoi(global->arr[1]);

	if (!(global->stack))
	{
		new_element->prev = NULL;
		new_element->next = NULL;
		global->stack = new_element;
	}
	else
	{
		new_element->next = global->stack;
		new_element->prev = (global->stack)->prev;
		(global->stack)->prev = new_element;
		global->stack = new_element;
	}

	return (new_element);
}
/**
 * add_node_queue - add element at the end of the queue
 * Return: new_element address
 */
stack_t *add_node_queue(void)
{
	stack_t *new_element = NULL;
	stack_t *tail = NULL;

	new_element = malloc(sizeof(stack_t));
	if (new_element == NULL)
		exit(error_display(2));

	new_element->n = atoi(global->arr[1]);

	if (!(global->stack))
	{
		new_element->prev = NULL;
		new_element->next = NULL;
		global->stack = new_element;
	}
	else
	{
		tail = global->stack;

		while (tail->next)
			tail = tail->next;

		new_element->next = tail->next;
		tail->next = new_element;
		new_element->prev = tail;
	}
	return (new_element);
}
