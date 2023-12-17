#ifndef RITCHIE_H
#define RITCHIE_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer n
 * @prev: points to the previous element
 * @next: points to the next element
 *
 * Description: doubly linked list node structure
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct var_global - global variables for monty interpreter
 * @arr: array for command arguments
 * @argv: arguments from the prompt
 * @ln: number of the line that is being processed
 * @command: command entered in array[0]
 * @op: opcode from the instructions structure
 * @fp: poniter to object in stream
 * @stack: pointer to stack
 *
 * Description: global variables for monty interpreter
 */
typedef struct var_global
{
	char **arr;
	char **argv;
	int status;
	unsigned int ln;
	char *op;
	char *command;
	FILE *fp;
	stack_t *stack;
} global_t;
global_t *global;

void push(stack_t **stack, unsigned int line_no);
void pall(stack_t **stack, unsigned int line_no);
void pint(stack_t **stack, unsigned int line_no);
void pop(stack_t **stack, unsigned int line_no);
void swap(stack_t **stack, unsigned int line_no);

void add(stack_t **stack, unsigned int line_no);
void nop(stack_t **stack, unsigned int line_no);
void sub(stack_t **stack, unsigned int line_no);
void _div(stack_t **stack, unsigned int line_no);
void mul(stack_t **stack, unsigned int line_no);
void mod(stack_t **stack, unsigned int line_no);

void pchar(stack_t **stack, unsigned int line_no);
void pstr(stack_t **stack, unsigned int line_no);
void rotl(stack_t **stack, unsigned int line_no);
void rotr(stack_t **stack, unsigned int line_no);
void queue(stack_t **stack, unsigned int line_no);
void stack(stack_t **stack, unsigned int line_no);

void initialize(global_t *global, char **argv);
void (*op_func(void))(stack_t **stack, unsigned int line_number);
char **split_cmd_line(char *line_cmd);
int _atoi(char *s);
int error_display(int error);
void fAll(void);
void fStack(stack_t *stack);
stack_t *add_node_stack(void);
stack_t *add_node_queue(void);
#endif/*header file */
