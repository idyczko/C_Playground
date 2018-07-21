#include "stack.h"

void *calloc(size_t, size_t);

struct stack_info {
	int start_index;
	int capacity;
};

static int *stack;
static struct stack_info *info;

void initialize_stacks(int stacks, size_t size) {
	stack = calloc(stacks*size, sizeof int);
	info = calloc(stacks, sizeof stack_info);
}

void free_stacks() {
	free(stack);
	free(info);
}

void push(int stack, int value) {

}
