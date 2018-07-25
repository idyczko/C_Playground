#ifndef MULTISTACK
#define MULTISTACK
#define MAX_CAPACITY 5
#define INIT_STACKS 2
#define GROWTH_FACTOR 2
#include <stdlib.h>
#include <stdio.h>

void *calloc(size_t, size_t);
void free(void *);

void init();
void free_stack();
void push(int);
int pop(int);
int top(int);
int is_empty();
void print_diagnostics();

#endif
