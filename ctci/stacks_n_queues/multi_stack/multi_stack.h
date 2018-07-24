#ifndef MULTISTACK
#define MULTISTACK
#define MAX_CAPACITY 5
#include <stdlib.h>

void *calloc(size_t, size_t);
void free(void *);

void init();
void free();
void push(int);
int pop();
int pop(int)
int top();
int top(int);
int is_empty();
void print_diagnostics();

#endif
