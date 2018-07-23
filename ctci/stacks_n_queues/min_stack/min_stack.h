#ifndef MIN_STACK
#define MIN_STACK
#define DEFAULT_SIZE 10
#include <stdlib.h>

void init_stack();
void push(int);
int pop();
int top();
int min();
int is_empty();

#endif
