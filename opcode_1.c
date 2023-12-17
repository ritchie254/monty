#include "ritchie.h"
/**
 * push - push a new element
 * @stack: stack
 * @line_no: line number
 */
void push(stack_t **stack, unsigned int line_no)
{
	int i = 0;

	global->ln = line_no;
	global->stack = *stack;

	if (global->arr[1] == NULL)
		exit(error_display(4));

	for (; global->arr[1][i] != '\0'; i++)
	{
		if ((isdigit(global->arr[1][i]) == 0) && global->arr[1][0] != '-')
			exit(error_display(4));
	}

	if (global->status == 0)
		add_node_stack();
	else
		add_node_queue();

}
/**
 * pall - print the element
 * @stack: stack
 * @line_no: line number or the command
 */
void pall(stack_t **stack, unsigned int line_no)
{
	stack_t *aux_stack = *stack;

	global->ln = line_no;

	while (aux_stack != NULL)
	{
		printf("%d\n", aux_stack->n);
		aux_stack = aux_stack->next;
	}

}
/**
 * pint - value at the top of a stack
 * @stack: stack
 * @line_no: line number or the command
 */
void pint(stack_t **stack, unsigned int line_no)
{
	global->ln = line_no;
	global->stack = *stack;

	if ((*stack) == NULL)
		exit(error_display(5));
	printf("%d\n", (*stack)->n);
}
/**
 * pop - poping an element from the stack
 * @stack: stack
 * @line_no: line number or the command
 */
void pop(stack_t **stack, unsigned int line_no)
{
	stack_t *top_element;

	global->ln = line_no;

	if (!(*stack))
		exit(error_display(6));

	top_element = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(top_element);

}
/**
 * swap - interchange the values of the first two elements
 * @stack: stack
 * @line_no: line number or the command
 */
void swap(stack_t **stack, unsigned int line_no)
{
	int num;

	global->ln = line_no;
	global->stack = *stack;

	if (!(*stack) || !((*stack)->next))
		exit(error_display(7));

	num = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = num;
}
