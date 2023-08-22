## Monty Bytecode Interpreter

```sh
. This is a bytecode interpreter for .m files
. Implements stacks, queues LIFO, FIFO
```

Written by `sebastian muchui`

## Introduction

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

#### Compilation

```sh
gcc -Wall -pedantic -Werror -Wextra std=gnu89 *.c -o monty
```

#### Usage

```sh
monty <filename>
```

The file path should be relative to the monty executable

#### Data Structures

```c
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

```

#### List of fundamental commands

```sh
push - pushes a new item to the stack
pall - prints all elements in the stack in LIFO order
pint - prints the top
pop - removes the top element
swap - swaps the top 2 elements
add - adds the top 2 elements
nop - basically does nothing
```
