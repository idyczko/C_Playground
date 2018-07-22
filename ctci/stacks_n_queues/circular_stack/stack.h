#ifndef CTCI_CIRCULAR_STACK
#define CTCI_CIRCULAR_STACK
#include <stdlib.h>
#include <stdio.h>

int *illegal_action();
void initialize_stacks(int stacks, size_t size);
void free_stacks(); 
void push(int stack, int value);
int pop(int stack);
int top(int stack);
int is_empty(int stack);

#endif
