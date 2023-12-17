#include "ritchie.h"
/**
 * nop - does nothing
 * @stack: stack
 * @line_no: line number or the command
 */
void nop(stack_t **stack, unsigned int line_no)
{
	(void)line_no;
	(void)stack;
}
/**
 * add - add the two first elements in a stack
 * @stack: stack
 * @line_no: line number or the command
 */
void add(stack_t **stack, unsigned int line_no)
{
	int r;/* result */
	(void)line_no;
	if (!(*stack) || !(*stack)->next)
		exit(error_display(7));

	r = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = r;
	pop(stack, line_no);

}
/**
 * sub - subtract the  first elements with the second in a stack
 * @stack: stack
 * @line_no: line number or the command
 */
void sub(stack_t **stack, unsigned int line_no)
{
	(void)line_no;
	if (!(*stack) || !(*stack)->next)
		exit(error_display(7));

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_no);

}
/**
 * _div - divide the two first elements in a stack
 * @stack: stack
 * @line_no: line number or the command
 */
void _div(stack_t **stack, unsigned int line_no)
{
	(void)line_no;
	if (!(*stack) || !(*stack)->next)
		exit(error_display(7));
	if ((*stack)->n == 0)
		exit(error_display(8));

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_no);

}
/**
 * mul - multiply the two first elements in a stack
 * @stack: stack
 * @line_no: line number or the command
 */
void mul(stack_t **stack, unsigned int line_no)
{
	(void)line_no;
	if (!(*stack) || !(*stack)->next)
		exit(error_display(7));

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_no);

}
