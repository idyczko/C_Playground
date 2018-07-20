#ifndef CTCI_CIRCULAR_STACK
#define CTCI_CIRCULAR_STACK

void initialize_stacks(int stacks, size_t size);
void push(int stack, int value);
int pop(int stack);
int top(int stack);
bool is_empty(int stack);

#endif
