#include "stack.h"

static int *stack;

void initialize_stacks(int stacks, size_t size) {
	stack = calloc(stacks*size, sizeof int);
}
