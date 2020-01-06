#ifndef FIFO
#define FIFO

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int main(int argc, char **argv);
int op_file(char *fileN);
void push_int(stack_t **head, unsigned int n);
int exect(char *cmd, char *arg, stack_t **head);
void (*get_function(char *opcode))(stack_t **stack, unsigned int line_number);
void free_n(void);
void pall_int(stack_t **stack, unsigned int line_number);
void freeAll(void);

/**
 * struct global_v - global variable
 * @head: poiter to head
 * @fp: file name
 * @line: pointer to line
 * @line_number: line number
 * @nValue: node value
 *
 * Description: global variable structure
 */

typedef struct global_v
{
	stack_t *head;
	FILE *fp;
	char *line;
	unsigned int line_number;
	char *nValue;
} global;
extern global globalVar;

#endif
